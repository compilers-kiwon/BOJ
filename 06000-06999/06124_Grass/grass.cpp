#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	GRID_SIZE	3

int		get_sum(const int& row,const int& col,const int grid[][MAX_SIZE])
{
	int	ret;
	
	ret = 0;
	
	for(int d_row=0;d_row<GRID_SIZE;d_row++)
	{
		for(int d_col=0;d_col<GRID_SIZE;d_col++)
		{
			ret += grid[row+d_row][col+d_col];
		}
	}
	
	return	ret;
}

void	input(int& row_size,int& col_size,int grid[][MAX_SIZE])
{
	cin>>row_size>>col_size;
	
	for(int row=1;row<=row_size;row++)
	{
		for(int col=1;col<=col_size;col++)
		{
			cin>>grid[row][col];
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	NR,NC,grid[MAX_SIZE][MAX_SIZE];
	int	max_row,max_col,max_grid;
	
	input(NR,NC,grid);
	max_grid = 0;

	for(int row=1;row<=NR-GRID_SIZE+1;row++)
	{
		for(int col=1;col<=NC-GRID_SIZE+1;col++)
		{
			int	sum;
			
			sum = get_sum(row,col,grid);
			
			if( sum > max_grid )
			{
				max_grid = sum;
				max_row = row;
				max_col = col;
			}
		}
	}
	
	cout<<max_grid<<'\n'<<max_row<<' '<<max_col<<'\n';
	
	return	0;	
}
