#include	<iostream>

using namespace	std;

#define	MAX_SIZE		(4*100-3)
#define	get_length(n)	(4*(n)-3)

int		N;
char	grid[MAX_SIZE][MAX_SIZE+1];

void	fill_grid(int n,int s_row,int s_col)
{
	if( n == 1 )
	{
		grid[s_row][s_col] = '*';
		return;
	}
	
	int	e_row,e_col;
	
	e_row = s_row+get_length(n);
	e_col = s_col+get_length(n);
	
	fill(&grid[s_row][s_col],&grid[s_row][e_col],'*');
	fill(&grid[s_row+1][s_col],&grid[s_row+1][e_col],' ');
	
	fill(&grid[e_row-2][s_col],&grid[e_row-2][e_col],' ');
	fill(&grid[e_row-1][s_col],&grid[e_row-1][e_col],'*');
	
	for(int row=s_row+1;row<e_row-1;row++)
	{
		grid[row][s_col] = grid[row][e_col-1] = '*';
		grid[row][s_col+1] = grid[row][e_col-2] = ' ';
	}
	
	fill_grid(n-1,s_row+2,s_col+2);
}

int		main(void)
{
	int	N;
	
	cin>>N;
	fill_grid(N,0,0);
	
	for(int row=0;row<get_length(N);row++)
	{
		cout<<&grid[row][0]<<'\n';
	}
	
	return	0;
}
