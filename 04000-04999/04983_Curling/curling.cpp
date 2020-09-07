#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(20+1)
#define	MAX_MOVE	10

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	VACANT	0
#define	BLOCK	1
#define	START	2
#define	GOAL	3

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		w,h,grid[MAX_SIZE][MAX_SIZE];
int		s_row,s_col,g_row,g_col;

bool	input(void)
{
	cin>>w>>h;
	
	if( w==0 && h==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			int&	g = grid[row][col];
			
			cin>>g;
			
			switch(g)
			{
				case	START:
					s_row = row;
					s_col = col;
					g = VACANT;
					break;
				case	GOAL:
					g_row = row;
					g_col = col;
					g = VACANT;
					break;
				default:
					// do nothing
					break;
			}
		}
	}
	
	return	true;
}

void	dfs(int current_row,int current_col,int current_move,int& min_move)
{
	if( current_move == min_move )
	{
		return;
	}
	
	for(int d=UP;d<=RIGHT;d++)
	{
		bool	out,goal,stop;
		int		adj_row,adj_col;
		
		adj_row = current_row;
		adj_col = current_col;
		out = goal = stop = false;
		
		for(int i=0;;i++)
		{
			adj_row += adj[d].d_row;
			adj_col += adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,h) || !IN_RANGE(1,adj_col,w) )
			{
				out = true;
				break;
			}
			
			if( adj_row==g_row && adj_col==g_col )
			{
				goal = true;
				break;
			}
			
			if( grid[adj_row][adj_col] == BLOCK )
			{
				if( i == 0 )
				{
					out = true;
				}
				else
				{
					stop = true;
				}
				break;
			}
		}
		
		if( out == true )
		{
			continue;
		}
		
		if( stop == true )
		{
			grid[adj_row][adj_col] = VACANT;
			adj_row -= adj[d].d_row;
			adj_col -= adj[d].d_col;
			
			dfs(adj_row,adj_col,current_move+1,min_move);
			
			adj_row += adj[d].d_row;
			adj_col += adj[d].d_col;
			grid[adj_row][adj_col] = BLOCK;
		}
		
		if( goal == true )
		{
			min_move = min(min_move,current_move+1);
			break;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		if( input() == false )
		{
			break;
		}
		
		int	result;
		
		result = MAX_MOVE+1;
		dfs(s_row,s_col,0,result);
		
		if( result == MAX_MOVE+1 )
		{
			result = -1;
		}
		
		cout<<result<<'\n';
	}
	
	return	0;
}
