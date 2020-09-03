#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

typedef	struct	_COUNT_INFO	Count;
struct	_COUNT_INFO
{
	int	sum_of_jungle,sum_of_sea,sum_of_ice;
};

int		M,N,K;
Count	row_table[MAX_SIZE][MAX_SIZE],col_table[MAX_SIZE][MAX_SIZE];
char	map[MAX_SIZE][MAX_SIZE+1];

void	init(void)
{
	scanf("%d %d %d",&M,&N,&K);
	
	for(int row=1;row<=M;row++)
	{
		scanf("%s",&map[row][1]);
	}
	
	for(int row=1;row<=M;row++)
	{
		for(int col=1;col<=N;col++)
		{
			row_table[row][col] = row_table[row][col-1];
			col_table[row][col] = col_table[row-1][col];
			
			char&	c = map[row][col];
			
			switch(c)
			{
				case	'J':
					row_table[row][col].sum_of_jungle++;
					col_table[row][col].sum_of_jungle++;
					break;
				case	'O':
					row_table[row][col].sum_of_sea++;
					col_table[row][col].sum_of_sea++;
					break;
				case	'I':
					row_table[row][col].sum_of_ice++;
					col_table[row][col].sum_of_ice++;
					break;
			}
		}
	}
}

void	get_count(int s_row,int s_col,int e_row,int e_col)
{
	int	row_diff,col_diff;
	int	num_of_jungle,num_of_sea,num_of_ice;
	
	row_diff = e_row-s_row;
	col_diff = e_col-s_col;
	num_of_jungle = num_of_sea = num_of_ice = 0;
	
	if( row_diff < col_diff )
	{
		for(int row=s_row;row<=e_row;row++)
		{
			num_of_jungle += row_table[row][e_col].sum_of_jungle-row_table[row][s_col-1].sum_of_jungle;
			num_of_sea += row_table[row][e_col].sum_of_sea-row_table[row][s_col-1].sum_of_sea;
			num_of_ice += row_table[row][e_col].sum_of_ice-row_table[row][s_col-1].sum_of_ice;
		}
	}
	else
	{
		for(int col=s_col;col<=e_col;col++)
		{
			num_of_jungle += col_table[e_row][col].sum_of_jungle-col_table[s_row-1][col].sum_of_jungle;
			num_of_sea += col_table[e_row][col].sum_of_sea-col_table[s_row-1][col].sum_of_sea;
			num_of_ice += col_table[e_row][col].sum_of_ice-col_table[s_row-1][col].sum_of_ice;
		}
	}
	
	printf("%d %d %d\n",num_of_jungle,num_of_sea,num_of_ice);
}

int		main(void)
{
	init();
	
	for(int i=1;i<=K;i++)
	{
		int	a,b,c,d;
		
		scanf("%d %d %d %d",&a,&b,&c,&d);
		get_count(a,b,c,d);
	}
	
	return	0;
}
