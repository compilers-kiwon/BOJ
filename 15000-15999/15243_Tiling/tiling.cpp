#include	<iostream>

using namespace	std;

#define	MAX_WIDTH	1000
#define	MAX_STATE	8
#define	MOD(n)		((n)%1000000007)

int	N,dp[MAX_WIDTH+1][MAX_STATE];

void	init(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<MAX_STATE;j++)
		{
			dp[i][j] = 0;
		}
	}
	
	dp[0][MAX_STATE-1] = 1;
}

int		main(void)
{
	init();
	
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<MAX_STATE;j++)
		{
			dp[i][j] = dp[i-1][MAX_STATE-1-j];
			
			if( j==3 || j==6 )
			{
				dp[i][j] = MOD(dp[i][j]+dp[i-1][MAX_STATE-1]);
			}
			else if( j == 7 )
			{
				dp[i][j] = MOD(dp[i][j]+MOD(dp[i-1][3]+dp[i-1][6]));
			}
		}
	}
	
	cout<<dp[N][7]<<'\n';
	
	return	0;
}
