#include	<iostream>
#include	<vector>
#include	<string>
#include	<queue>

using namespace	std;

#define	IS_WALL(c)	((c)=='X')
#define	IS_EXIT(c)	((c)=='O'||(c)=='0')
#define	IS_GOAL(c)	((c)=='G')
#define	IS_START(c)	((c)=='S')

#define	INF	0x7FFFFFFF

typedef	struct	_ROBOT_INFO	Robot;
struct	_ROBOT_INFO
{
	int	row,col,num_of_moves;
};

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	(MIN<=(n)&&(n)<=(MAX))

void	input(int& row_size,int& col_size,vector<string>& maze)
{
	cin>>row_size>>col_size;
	
	maze.resize(row_size+1);
	
	for(int row=1;row<=row_size;row++)
	{
		cin>>maze[row];
		maze[row].insert(maze[row].begin(),' ');
	}
}

void	get_start_pos(int& s_row,int& s_col,vector<string>& maze)
{
	bool	found;
	
	found = false;
	
	for(int row=1;row<maze.size()&&found!=true;row++)
	{
		string&	r = maze[row];
		
		for(int col=1;col<r.length()&&found!=true;col++)
		{
			if( IS_START(maze[row][col]) == true )
			{
				s_row = row;
				s_col = col;
				
				found = true;
			}
		}
	}
}

int		bfs(int s_row,int s_col,vector<string>& maze,vector<bool>* visited)
{
	queue<Robot>	robot_q;
	Robot			r;
	int				shortest_path_len,row_size,col_size;
	
	r.row = s_row;
	r.col = s_col;
	r.num_of_moves = 0;
	
	row_size = maze.size()-1;
	col_size = maze[1].length()-1;
	
	robot_q.push(r);
	shortest_path_len = INF;
	visited[s_row][s_col] = true;
	
	for(;!robot_q.empty();)
	{
		Robot	current;
		
		current = robot_q.front();
		robot_q.pop();
		
		if( IS_GOAL(maze[current.row][current.col]) == true )
		{
			shortest_path_len = current.num_of_moves;
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current.row+adj[d].d_row;
			adj_col = current.col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,row_size) && IN_RANGE(1,adj_col,col_size) )
			{
				if( !IS_WALL(maze[adj_row][adj_col]) && visited[adj_row][adj_col]== false )
				{
					r.row = adj_row;
					r.col = adj_col;
					r.num_of_moves = current.num_of_moves+1;
					
					visited[adj_row][adj_col] = true;
					robot_q.push(r);
				}
			}
		}
	}
	
	return	shortest_path_len;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	for(cin>>T;T>0;T--)
	{
		int				R,C,s_row,s_col,shortest_path_len;
		vector<string>	maze;
		
		input(R,C,maze);
		get_start_pos(s_row,s_col,maze);
		
		vector<bool>	visited[R+1];
		
		for(int row=1;row<=R;row++)
		{
			visited[row].resize(C+1,false);
		}
		
		shortest_path_len = bfs(s_row,s_col,maze,visited);
		
		if( shortest_path_len == INF )
		{
			cout<<"No Exit\n";
		}
		else
		{
			cout<<"Shortest Path: "<<shortest_path_len<<'\n';
		}
	}
	
	return	0;
}
