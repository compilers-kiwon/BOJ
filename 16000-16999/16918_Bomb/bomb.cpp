#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(200+1)
#define	EMPTY		-1

int	R,C,N,grid[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	input(void)
{
	cin>>R>>C>>N;
	
	for(int row=1;row<=R;row++)
	{
		char	buf[MAX_SIZE+1];
		
		cin>>&buf[1];
		
		for(int col=1;col<=C;col++)
		{
			if( buf[col] == '.' )
			{
				grid[row][col] = -1;
			}
		}
	}
}

void	place_bomb(int t)
{
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( grid[row][col] == EMPTY )
			{
				grid[row][col] = t;
			}
		}
	}
}

void	explode_bomb(int t)
{
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( grid[row][col] == t-3 )
			{
				grid[row][col] = EMPTY;
				
				for(int d=UP;d<=RIGHT;d++)
				{
					int	adj_row,adj_col;
					
					adj_row = row+adj[d].d_row;
					adj_col = col+adj[d].d_col;
					
					if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C)
						|| grid[adj_row][adj_col]==EMPTY )
					{
						continue;
					}
					
					if( grid[adj_row][adj_col] != t-3 )
					{
						grid[adj_row][adj_col] = EMPTY;
					}
				}
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=0,t=1;t<=N;i++,t++)
	{
		switch(i%2)
		{
			case	0 :
				explode_bomb(t);
				break;
			case	1:
				place_bomb(t);
				break;
			default:
				// do nothing
				break;
		}
	}
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( grid[row][col] == EMPTY )
			{
				cout<<'.';
			}
			else
			{
				cout<<'O';
			}
		}
		cout<<'\n';
	}
	
	return	0;
}
