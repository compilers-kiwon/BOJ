#include	<iostream>

using namespace	std;

#define	MAX_NUM		4000
#define	MAX_WIDTH	(MAX_NUM*2)
#define	MAX_HEIGHT	(MAX_NUM+1)

int		N;
char	buf[MAX_HEIGHT][MAX_WIDTH+1];

void	print_star(int s_row,int s_col)
{
	buf[s_row][s_col] = '*';
	buf[s_row+1][s_col-1] = buf[s_row+1][s_col+1] = '*';
	buf[s_row+2][s_col-2] = buf[s_row+2][s_col-1] = buf[s_row+2][s_col] = buf[s_row+2][s_col+1] = buf[s_row+2][s_col+2] = '*';
}

void	print(int num_of_triangle,int s_row,int s_col)
{
	if( num_of_triangle == 1 )
	{
		print_star(s_row,s_col);
	}
	else
	{
		print(num_of_triangle/2,s_row,s_col);
		print(num_of_triangle/2,s_row+(num_of_triangle/2)*3,s_col-(num_of_triangle/2)*3);
		print(num_of_triangle/2,s_row+(num_of_triangle/2)*3,s_col+(num_of_triangle/2)*3);
	}
}

int		main(void)
{
	scanf("%d",&N);
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N*2;col++)
		{
			buf[row][col] = ' ';
		}
	}
	
	print(N/3,1,N);
	
	for(int	row=1;row<=N;row++)
	{
		puts(&buf[row][1]);
	}
	
	return	0;
}	
