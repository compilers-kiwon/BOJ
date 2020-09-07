#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_SEATS	(40+1)

int	main(void)
{
	int		N,M,dp[MAX_NUM_OF_SEATS];
	bool	vip[MAX_NUM_OF_SEATS];
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		vip[i] = false;
		dp[i] = -1;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	s;
		
		cin>>s;
		vip[s] = true;
	}
	
	dp[0] = dp[1] = 1;
	
	for(int i=2;i<=N;i++)
	{
		if( vip[i] == true )
		{
			dp[i] = dp[i-1];
		}
		else
		{
			if( vip[i-1] == true )
			{
				dp[i] = dp[i-1];
			}
			else
			{
				dp[i] = dp[i-1]+dp[i-2];
			}
		}
	}
	cout<<dp[N]<<endl;
	
	return	0;
}
