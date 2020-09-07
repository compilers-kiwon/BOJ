#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+2)

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	TURN_RIGHT(d)	(((d)+1)%MAX_DIR)

#define	row	first
#define	col	second

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{1,0},{0,1},{-1,0},{0,-1}};

typedef	pair<int,int>	Pos;
typedef	pair<int,Pos>	State;

void	input(int& size,int& num_of_mirror,bool is_mirror[][MAX_SIZE],Pos& s)
{
	cin>>size>>num_of_mirror;
	
	for(int r=0;r<=size+1;r++)
	{
		for(int c=0;c<=size+1;c++)
		{
			is_mirror[r][c] = false;
		}
	}
	
	for(int i=1;i<=num_of_mirror;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		is_mirror[y][x] = true;	
	}
	
	cin>>s.col>>s.row;
}

int		get_initial_direction(Pos& s,int size)
{
	int	ret;
	
	if( s.row == size+1 )
	{
		ret = DOWN;
	}
	else if( s.row == 0 )
	{
		ret = UP;
	}
	else if( s.col == size+1 )
	{
		ret = LEFT;
	}
	else
	{
		ret = RIGHT;
	}
	
	return	ret;
}

Pos		solve(int size,bool is_mirror[][MAX_SIZE],Pos& s,int d)
{
	queue<State>	state_q;
	bool			visited[MAX_SIZE][MAX_SIZE][MAX_DIR];
	Pos				ret;
	
	for(int row=0;row<=size+1;row++)
	{
		for(int col=0;col<=size+1;col++)
		{
			visited[row][col][UP] = visited[row][col][DOWN]
			= visited[row][col][LEFT] = visited[row][col][RIGHT] = false;
		}
	}
	
	ret = make_pair(0,0);
	visited[s.row][s.col][d] = true;
	state_q.push(make_pair(d,s));
	
	for(;!state_q.empty();)
	{
		int	current_row,current_col,current_dir;
		
		current_row = state_q.front().second.row;
		current_col = state_q.front().second.col;
		current_dir = state_q.front().first;
		
		state_q.pop();
		
		if( current_row==0 || current_row==size+1 || 
			current_col==0 || current_col==size+1 )
		{
			ret.row = current_row;
			ret.col = current_col;
			
			break;
		}
		
		int	adj_row,adj_col,adj_dir;
		
		if( is_mirror[current_row][current_col] == true )
		{
			adj_dir = TURN_RIGHT(current_dir);
		}
		else
		{
			adj_dir = current_dir;
		}
		
		adj_row = current_row+adj[adj_dir].d_row;
		adj_col = current_col+adj[adj_dir].d_col;
		
		if( visited[adj_row][adj_col][adj_dir] == false )
		{
			visited[adj_row][adj_col][adj_dir] = true;
			state_q.push(make_pair(adj_dir,make_pair(adj_row,adj_col)));
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	for(cin>>T;T>0;T--)
	{
		int		n,r,d;
		bool	m[MAX_SIZE][MAX_SIZE];
		Pos		start,end;
		
		input(n,r,m,start);
		d = get_initial_direction(start,n);
		
		start.row += adj[d].d_row;
		start.col += adj[d].d_col;
		
		end = solve(n,m,start,d);
		
		cout<<end.col<<' '<<end.row<<'\n';
	}
	
	return	0;
}
