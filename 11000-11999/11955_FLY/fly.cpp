#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	FLY			'*'

int		R,S,K;
char	window[MAX_SIZE][MAX_SIZE+1];

int	count_num_of_killed_flies(int s_row,int s_col,int e_row,int e_col)
{
	int	cnt,row,col;
	
	for(cnt=0,row=s_row+1;row<e_row;row++)
	{
		for(col=s_col+1;col<e_col;col++)
		{
			if( window[row][col] == FLY )
			{
				cnt++;
			}
		}
	}
	
	return	cnt;
}

int	main(void)
{
	scanf("%d %d %d",&R,&S,&K);
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&window[row][1]);
	}
	
	int	max_num_of_flies,max_s_row,max_s_col,max_e_row,max_e_col;
	
	max_num_of_flies = 0;
	
	for(int row=1;row<=R-K+1;row++)
	{
		for(int col=1;col<=S-K+1;col++)
		{
			int	f;
			
			f = count_num_of_killed_flies(row,col,row+K-1,col+K-1);
			
			if( max_num_of_flies < f )
			{
				max_num_of_flies = f;
				
				max_s_row = row;
				max_s_col = col;
				max_e_row = row+K-1;
				max_e_col = col+K-1;
			}
		}
	}
	
	for(int col=max_s_col+1;col<max_e_col;col++)
	{
		window[max_s_row][col] = window[max_e_row][col] = '-';
	}
	
	for(int row=max_s_row+1;row<max_e_row;row++)
	{
		window[row][max_s_col] = window[row][max_e_col] = '|';
	}
	
	window[max_s_row][max_s_col] = window[max_s_row][max_e_col] =
	window[max_e_row][max_s_col] = window[max_e_row][max_e_col] = '+';
	
	printf("%d\n",max_num_of_flies);
	
	for(int row=1;row<=R;row++)
	{
		puts(&window[row][1]);
	}
	
	return	0;
}
