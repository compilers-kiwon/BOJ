#include	<iostream>

using namespace	std;

#define	GRID_SIZE	3

#define	DOWN		0
#define	RIGHT		1
#define	RIGHT_DOWN	2
#define	LEFT_DOWN	3
#define	MAX_DIR		4

#define	EMPTY		'-'

const struct
{
	int	d_row,d_col;
} adj[MAX_DIR] = {{1,0},{0,1},{1,1},{1,-1}};

bool	win(char grid[][GRID_SIZE+2],char nam,int d,int s_row,int s_col)
{
	int	cnt;
	
	cnt = 0;
	
	for(int i=0;i<GRID_SIZE;i++)
	{
		int	adj_row,adj_col;
		
		adj_row = s_row+adj[d].d_row*i;
		adj_col = s_col+adj[d].d_col*i;
		
		if( nam == grid[adj_row][adj_col] )
		{
			cnt++;
		}
	}
	
	return	(cnt==GRID_SIZE);
}

int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	for(int t=1;t<=T;t++)
	{
		char	grid[GRID_SIZE+1][GRID_SIZE+2];
		char	nam;
		bool	result;
		
		cout<<"Case "<<t<<":\n";
		result = false;
		
		for(int row=1;row<=GRID_SIZE;row++)
		{
			scanf("%s",&grid[row][1]);
		}
		
		getchar();scanf("%c",&nam);
		
		for(int row=1;row<=GRID_SIZE&&result!=true;row++)
		{
			for(int col=1;col<=GRID_SIZE&&result!=true;col++)
			{
				if( grid[row][col] != EMPTY )
				{
					continue;
				}
				
				grid[row][col] = nam;
				result = win(grid,nam,RIGHT,row,1) | win(grid,nam,DOWN,1,col);
				
				if( result==false && row==col )
				{
					result = win(grid,nam,RIGHT_DOWN,1,1);
				}
				
				if( result==false && row+col==GRID_SIZE+1 )
				{
					result = win(grid,nam,LEFT_DOWN,1,3);
				}
				
				if( result == true )
				{
					for(int r=1;r<=GRID_SIZE;r++)
					{
						puts(&grid[r][1]);
					}
				}
				
				grid[row][col] = EMPTY;
			}
		}
	}
	
	return	0;
}
