#include	<iostream>

using namespace	std;

#define	MAX_NUM	(1000000+1)
#define	MOD(n)	((n)%15746)

int	dp[MAX_NUM];

int	main(void)
{
	int	N;
	
	cin>>N;
	
	dp[1] = 1;
	dp[2] = 2;
	
	for(int i=3;i<=N;i++)
	{
		dp[i] = MOD(dp[i-1]+dp[i-2]);
	}
	cout<<dp[N]<<endl;
    
    return    0;
}
