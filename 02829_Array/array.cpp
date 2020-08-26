#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(400+2)
#define	INF			(-1000*MAX_SIZE*MAX_SIZE)

int	N,grid[MAX_SIZE][MAX_SIZE];
int	left_to_right[MAX_SIZE][MAX_SIZE];
int	right_to_left[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>grid[row][col];
		}
	}
}

void	get_sum(void)
{
	// 1. left->right
	for(int col=1;col<=N;col++)
	{
		for(int tmp_row=1,tmp_col=col;tmp_col<=N;tmp_row++,tmp_col++)
		{
			left_to_right[tmp_row][tmp_col] =
				left_to_right[tmp_row-1][tmp_col-1]+grid[tmp_row][tmp_col];
		}
	}
	
	for(int row=2;row<=N;row++)
	{
		for(int tmp_row=row,tmp_col=1;tmp_row<=N;tmp_row++,tmp_col++)
		{
			left_to_right[tmp_row][tmp_col] =
				left_to_right[tmp_row-1][tmp_col-1]+grid[tmp_row][tmp_col];
		}
	}
	
	// 2. right->left
	for(int col=N;col>=1;col--)
	{
		for(int tmp_row=1,tmp_col=col;tmp_col>=1;tmp_row++,tmp_col--)
		{
			right_to_left[tmp_row][tmp_col] =
				right_to_left[tmp_row-1][tmp_col+1]+grid[tmp_row][tmp_col];
		}
	}
	
	for(int row=2;row<=N;row++)
	{
		for(int tmp_row=row,tmp_col=N;tmp_row<=N;tmp_row++,tmp_col--)
		{
			right_to_left[tmp_row][tmp_col] =
				right_to_left[tmp_row-1][tmp_col+1]+grid[tmp_row][tmp_col];
		}
	}
}


int		get_max_value(void)
{
	int	ret;
	
	ret = INF;
	
	for(int s_row=1;s_row<=N;s_row++)
	{
		for(int s_col=1;s_col<=N;s_col++)
		{
			for(int e_row=s_row,e_col=s_col;e_row<=N&&e_col<=N;e_row++,e_col++)
			{
				int	sum1,sum2;
				
				sum1 = left_to_right[e_row][e_col]-left_to_right[s_row-1][s_col-1];
				sum2 = right_to_left[e_row][s_col]-right_to_left[s_row-1][e_col+1];
				
				ret = max(ret,sum1-sum2);
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	get_sum();
	cout<<get_max_value()<<'\n';
	
	return	0;
}
