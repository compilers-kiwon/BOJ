#include	<iostream>

using namespace	std;

#define	MAX_LEN	(100+1)

typedef	unsigned long long	uint64;

int	main(void)
{
	int		N;
	uint64	dp[MAX_LEN];
	
	cin>>N;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for(int i=4;i<=N;i++)
	{
		dp[i] = dp[i-1]+1;
		
		for(int j=3;j<i;j++)
		{
			dp[i] = max(dp[i],dp[j-2]+dp[j-2]*(i-j));
		}
	
	}
	cout<<dp[N]<<endl;
	
	return	0;
}
