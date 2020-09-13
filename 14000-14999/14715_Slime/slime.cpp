#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_NUM	1000000

int	dp[MAX_NUM+1];

int	get_dp(int K)
{
	int	left_dp,right_dp,heavy;
	
	if( dp[K] != -1 )
	{
		return	dp[K];
	}
	
	dp[K] = 0x7FFFFFFF;
	
	for(int A=2;A<=sqrt(K);A++)
	{
		if( K%A == 0 )
		{
			int	B;
			
			B = K/A;
			
			if( B >= 2 )
			{
				left_dp = get_dp(A);
				right_dp = get_dp(B);
				heavy = max(left_dp,right_dp)+1;
				
				dp[K] = min(dp[K],heavy);
			}
		}
	}
	
	if( dp[K] == 0x7FFFFFFF )
	{
		dp[K] = 0;
	}
	
	return	dp[K];
}

int	main(void)
{
	int	K;
	
	cin>>K;
	
	for(int i=1;i<=K;i++)
	{
		dp[i] = -1;
	}
	
	cout<<get_dp(K)<<endl;
	
	return	0;
}
