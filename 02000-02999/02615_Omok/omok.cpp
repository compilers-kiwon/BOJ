#include	<iostream>

using namespace	std;

#define	MAX_SIZE	19
#define	MAX_DIR		4

#define	EMPTY		0
#define	BLACK		1
#define	WHITE		2
#define	WIN_LENGTH	5

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{0,1},{1,1},{1,0},{1,-1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		grid[MAX_SIZE+1][MAX_SIZE+1];
bool	checked[MAX_SIZE+1][MAX_SIZE+1][MAX_DIR];

int		get_consecutive_length(int row,int col,int direction,
							   int current_length,int color)
{
	int	adj_row,adj_col,ret;
	
	adj_row = row+adj[direction].d_row;
	adj_col = col+adj[direction].d_col;
	
	if( !IN_RANGE(1,adj_row,MAX_SIZE) || !IN_RANGE(1,adj_col,MAX_SIZE) )
	{
		return	current_length;
	}
	
	if( grid[adj_row][adj_col] == color )
	{
		checked[adj_row][adj_col][direction] = true;
		ret = get_consecutive_length(adj_row,adj_col,direction,current_length+1,color);
	}
	else
	{
		ret = current_length;
	}
	
	return	ret;
}

void	input(void)
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			cin>>grid[row][col];
		}
	}
}

int		main(void)
{
	int	winner,winner_row,winner_col;
	
	input();
	winner = EMPTY;
	
	for(int row=1;row<=MAX_SIZE&&winner==EMPTY;row++)
	{
		for(int col=1;col<=MAX_SIZE&&winner==EMPTY;col++)
		{
			for(int d=0;d<MAX_DIR;d++)
			{
				if( grid[row][col]!=EMPTY && checked[row][col][d]==false )
				{
					checked[row][col][d] = true;
					
					if( get_consecutive_length(row,col,d,1,grid[row][col]) == WIN_LENGTH )
					{
						winner = grid[row][col];
						
						if( d == MAX_DIR-1 )
						{
							winner_row = row+(WIN_LENGTH-1);
							winner_col = col-(WIN_LENGTH-1);	
						}
						else
						{
							winner_row = row;
							winner_col = col;
						}
					}
				}
			}
		}
	}
	
	cout<<winner<<'\n';
	
	if( winner != EMPTY )
	{
		cout<<winner_row<<' '<<winner_col<<'\n';
	}
	
	return	0;
}
