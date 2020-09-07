#include	<iostream>

using namespace	std;

#define	MAX_NUM			200
#define	MAX_COMBINATION	200
#define	MOD(n)			((n)%1000000000)

typedef	long long int	int64;

int		N,K;
int64	dp[MAX_NUM+1][MAX_COMBINATION+1];

void	init(void)
{
	cin>>N>>K;
	
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=K;j++)
		{
			dp[i][j] = -1;
		}
	}
	
	dp[0][0] = 1;
	
	for(int i=1;i<=N;i++)
	{
		dp[i][0] = 0;
	}
}

int64	get_dp(int n,int k)
{
	int64&	ret = dp[n][k];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	for(int i=0;i<=n;i++)
	{
		ret = MOD(ret+get_dp(n-i,k-1));
	}
	
	return	ret;
}

int		main(void)
{
	init();
	cout<<get_dp(N,K)<<'\n';
	
	return	0;
}
