#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(300+1)

int	N,profit[MAX_SIZE][MAX_SIZE],sum_table[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>profit[row][col];
		}
	}
}

void	build_sum_table(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			sum_table[row][col] = sum_table[row][col-1]+profit[row][col];
		}
	}
}

int		get_profit(int s_row,int s_col,int size)
{
	int	ret;
	
	ret = 0;
	
	for(int row=s_row;row<s_row+size;row++)
	{
		ret += sum_table[row][s_col+size-1]-sum_table[row][s_col-1];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	build_sum_table();
	
	int	max_profit;
	
	max_profit = MAX_SIZE*MAX_SIZE*(-1000);
	
	for(int K=1;K<=N;K++)
	{
		for(int row=1;row<=N;row++)
		{
			for(int col=1;col<=N;col++)
			{
				if( row+K-1<=N && col+K-1<=N )
				{
					max_profit = max(max_profit,get_profit(row,col,K));
				}
			}
		}
	}
	
	cout<<max_profit<<'\n';
	
	return	0;
}
