#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

typedef	long long	int64;

int64	map[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE+1];
int64	tmp_dp[MAX_SIZE+1];

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%lld",&map[i][j]);
		}
	}
	
	for(int col=1;col<=M;col++)
	{
		dp[1][col] = map[1][col]+dp[1][col-1];
	}
	
	for(int row=2;row<N;row++)
	{
		dp[row][0] = -2000000000;
		
		for(int col=1;col<=M;col++)
		{
			dp[row][col] = max(dp[row][col-1],dp[row-1][col])+map[row][col];
		}
		
		tmp_dp[N+1] = -2000000000;
		
		for(int col=M;col>=1;col--)
		{
			tmp_dp[col] = max(tmp_dp[col+1],dp[row-1][col])+map[row][col];
			dp[row][col] = max(tmp_dp[col],dp[row][col]);
		}
	}
	
	dp[N][0] = -2000000000;
	
	for(int col=1;col<=M;col++)
	{
		dp[N][col] = max(dp[N][col-1],dp[N-1][col])+map[N][col];
	}
	
	printf("%lld\n",dp[N][M]);
	
	return	0;
}
