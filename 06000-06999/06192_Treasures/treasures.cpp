#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

int R,C,grid[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			cin>>grid[row][col];
		}
	}
	
	dp[1][1] = grid[1][1];
}

void	get_dp(void)
{
	for(int col=2;col<=C;col++)
	{
		for(int row=1;row<=min(col,R);row++)
		{
			int	prev_max;
			
			prev_max = 0;
			
			for(int d=-1;d<=1;d++)
			{
				prev_max = max(prev_max,dp[row+d][col-1]);
			}
			
			dp[row][col] = prev_max+grid[row][col];
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	get_dp();
	
	cout<<dp[R][C]<<'\n';
	
	return	0;
}
