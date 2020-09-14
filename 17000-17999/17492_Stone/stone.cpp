#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(10+1)

#define	EMPTY	0
#define	WALL	1
#define	STONE	2

int	N,grid[MAX_SIZE][MAX_SIZE];

int		input(void)
{
	int	ret;
	
	cin>>N;
	ret = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>grid[row][col];
			
			if( grid[row][col] == STONE )
			{
				ret++;
			}
		}
	}
	
	return	ret;
}

bool	dfs(int cnt_of_stones)
{
	if( cnt_of_stones == 1 )
	{
		return	true;
	}
	
	for(int row=2;row<=N-1;row++)
	{
		for(int col=2;col<=N-1;col++)
		{
			if( grid[row][col] != STONE )
			{
				continue;
			}
			
			for(int d_row=-1;d_row<=1;d_row++)
			{
				for(int d_col=-1;d_col<=1;d_col++)
				{
					int	adj_row,adj_col;
				
					adj_row = row+d_row;
					adj_col = col+d_col;
					
					if( grid[adj_row][adj_col] == STONE )
					{
						int	dst_row,dst_col;
						
						dst_row = adj_row+d_row;
						dst_col = adj_col+d_col;
						
						if( grid[dst_row][dst_col] == EMPTY )
						{
							grid[row][col] = grid[adj_row][adj_col] = EMPTY;
							grid[dst_row][dst_col] = STONE;
							
							if( dfs(cnt_of_stones-1) == true )
							{
								return	true;
							}
							
							grid[dst_row][dst_col] = EMPTY;
							grid[row][col] = grid[adj_row][adj_col] = STONE;
						}
					}
				}
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	int	num_of_stones;
	
	num_of_stones = input();
	
	if( dfs(num_of_stones) == true )
	{
		cout<<"Possible\n";
	}
	else
	{
		cout<<"Impossible\n";
	}
	
	return	0;
}
