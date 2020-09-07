#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_STONE	(1000+1)

#define	SK	0
#define	CY	1

int	dp[MAX_NUM_OF_STONE];

int	get_dp(int stone)
{
	int&	ret = dp[stone];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	if( get_dp(stone-1) == CY || get_dp(stone-3) == CY || get_dp(stone-4) == CY )
	{
		ret = SK;
	}
	else
	{
		ret = CY;
	}
	
	return	ret;	
}

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		dp[i] = -1;
	}
	
	dp[1] = dp[3] = dp[4] = SK;
	dp[2] = CY;
	
	if( get_dp(N) == CY )
	{
		cout<<"CY\n";
	}
	else
	{
		cout<<"SK\n";
	}
	return	0;
}
