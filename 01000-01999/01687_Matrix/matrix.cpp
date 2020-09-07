#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(333+1)

int		N,M;
int		zero_height_table[MAX_SIZE][MAX_SIZE];
char	matrix[MAX_SIZE][MAX_SIZE+1];

void	build_zero_height_table(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( matrix[row][col] == '1' )
			{
				zero_height_table[row][col] = 0;
			}
			else
			{
				zero_height_table[row][col] = zero_height_table[row-1][col]+1;
			}
		}
	}
}

int		get_max_size(void)
{
	int	max_size;
	
	max_size = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( matrix[row][col] == '1' )
			{
				continue;
			}
			
			int	height = MAX_SIZE;
			
			for(int k=col;k>=1;k--)
			{
				height = min(zero_height_table[row][k],height);
				max_size = max(max_size,height*(col-k+1));
			}
		}
	}
	
	return	max_size;
}

int		main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&matrix[row][1]);
	}
	
	build_zero_height_table();
	
	printf("%d\n",get_max_size());
	
	return	0;
}
