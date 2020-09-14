#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(10+1)

#define	FREE		'.'
#define	OBSTACLE	'#'

void	input(int& size,char grid[][MAX_SIZE+1],int cnt_in_row[][MAX_SIZE])
{
	cin>>size;
		
	for(int row=1;row<=size;row++)
	{
		cin>>&grid[row][1];
		cnt_in_row[row][0] = 0;
		
		for(int col=1;col<=size;col++)
		{
			int&	prev_cnt = cnt_in_row[row][col-1];
			char&	current = grid[row][col];
			
			cnt_in_row[row][col] = prev_cnt+(current==FREE?1:0);
		}
	}
}

bool	is_square(int s_row,int s_col,int e_row,int e_col,
			      int len,int cnt_in_row[][MAX_SIZE])
{
	int	cnt;
	
	cnt = 0;
	
	for(int row=s_row;row<=e_row;row++)
	{
		cnt += cnt_in_row[row][e_col]-cnt_in_row[row][s_col-1];
	}
	
	return	(cnt==len*len?true:false);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int		N,cnt_in_row[MAX_SIZE][MAX_SIZE];
		char	grid[MAX_SIZE][MAX_SIZE+1];
		
		input(N,grid,cnt_in_row);
		
		int		max_square_length;
		bool	found;
		
		max_square_length = 0;
		
		for(int l=N;l>=1&&found!=true;l--)
		{
			for(int row=1;row+(l-1)<=N&&found!=true;row++)
			{
				for(int col=1;col+(l-1)<=N&&found!=true;col++)
				{
					if( is_square(row,col,row+(l-1),col+(l-1),l,cnt_in_row) )
					{
						max_square_length = max(max_square_length,l);
					}
				}
			}
		}
		
		cout<<max_square_length<<'\n';
	}
	
	return	0;
}
