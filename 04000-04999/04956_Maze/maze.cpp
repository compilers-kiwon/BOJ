#include	<iostream>
#include	<string>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(30+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
}adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

#define	EMPTY	'0'
#define	WALL	'1'

int		w,h;
bool	blocked[MAX_SIZE][MAX_SIZE][MAX_DIR];

typedef	pair<int,int>	Pos;	// first:row,second:col

bool	input(vector<string>& grid)
{
	cin>>w>>h;getchar();
	
	if( w==0 && h==0 )
	{
		return	false;
	}
	
	for(int row=0;row<2*h-1;row++)
	{
		string	buf;
		
		getline(cin,buf);
		
		if( buf.length() != (2*w-1) )
		{
			buf.push_back(' ');
		}
		
		grid.push_back(buf);
	}
	
	return	true;
}

void	parse_grid(vector<string>& grid)
{
	for(int row=0;row<2*h-1;row+=2)
	{
		for(int col=0;col<2*w-1;col+=2)
		{
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = row+adj[d].d_row;
				adj_col = col+adj[d].d_col;
				
				if( !IN_RANGE(0,adj_row,2*h-1) || !IN_RANGE(0,adj_col,2*w-1) )
				{
					blocked[row/2][col/2][d] = true;
					continue;
				}
				
				if( grid[adj_row][adj_col] == EMPTY )
				{
					blocked[row/2][col/2][d] = false;
				}
				else
				{
					blocked[row/2][col/2][d] = true;
				}
			}
		}
	}
}

int		bfs(void)
{
	queue<Pos>	pos_q;
	bool		visited[MAX_SIZE][MAX_SIZE];
	
	for(int row=0;row<h;row++)
	{
		fill(&visited[row][0],&visited[row][w],false);
	}
	
	visited[0][0] = true;
	pos_q.push(make_pair(0,0));
	
	for(int cnt=1;!pos_q.empty();cnt++)
	{
		for(int i=1,size=pos_q.size();i<=size;i++)
		{
			int	current_row,current_col;
			
			current_row = pos_q.front().first;
			current_col = pos_q.front().second;
			
			pos_q.pop();
			
			if( current_row==(h-1) && current_col==(w-1) )
			{
				return	cnt;
			}
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[d].d_row;
				adj_col = current_col+adj[d].d_col;
				
				if( !IN_RANGE(0,adj_row,h) || !IN_RANGE(0,adj_col,w) )
				{
					continue;
				}
				
				if( visited[adj_row][adj_col]==false 
					&& blocked[current_row][current_col][d]==false )
				{
					visited[adj_row][adj_col] = true;
					pos_q.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
	
	return	0;
}

int		main(void)
{
	for(;;)
	{
		vector<string>	grid;
		
		if( input(grid) == false )
		{
			break;
		}
		
		parse_grid(grid);
		cout<<bfs()<<'\n';
	}
	
	return	0;
}
