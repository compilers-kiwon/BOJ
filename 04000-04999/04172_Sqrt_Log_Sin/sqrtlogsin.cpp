#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_NUM	1000000

int	dp[MAX_NUM+1];

int	get_dp(int index)
{
	if( dp[index] != 0 )
	{
		return dp[index];
	}
	
	dp[index] = (get_dp(index-sqrt(index))+get_dp(log(index))+get_dp(index*(sin(index)*sin(index))))%1000000;
	
	return	dp[index];
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	dp[0] = 1;
	
	while(1)
	{
		int	i;
		
		cin>>i;
		
		if( i == -1 )
		{
			break;
		}
		
		cout<<get_dp(i)<<'\n';
	}
	
	return	0;
}
