#include	<iostream>

using namespace	std;

#define	MAX_SIZE	1000000
#define	MOD(n)		((n)%1000000009)

typedef	unsigned long long	uint64;

uint64	dp[MAX_SIZE+1];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for(int i=4;i<=MAX_SIZE;i++)
	{
		dp[i] = MOD(dp[i-1]+dp[i-2]+dp[i-3]);
	}
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	n;
		
		cin>>n;
		cout<<dp[n]<<'\n';
	}
	
	return	0;
}
