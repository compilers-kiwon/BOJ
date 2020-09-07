#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_VALUE	(1000+1)

int	get_dp(int* dp,int value,vector<int>& coin)
{
	int&	ret = dp[value];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	int	min_num_of_coin;
	
	min_num_of_coin = MAX_VALUE;
	
	for(int i=0;i<coin.size();i++)
	{
		int	tmp_value;
		
		tmp_value = value-coin[i];
		
		if( tmp_value > 0 )
		{
			min_num_of_coin = min(min_num_of_coin,get_dp(dp,tmp_value,coin));
		}
	}
	
	ret = min_num_of_coin+1;
	
	return	ret;
}

int	main(void)
{
	int			C,N,dp[MAX_VALUE];
	vector<int>	coin;
	
	cin>>C>>N;
	
	for(int i=1;i<=C;i++)
	{
		dp[i] = -1;
	}
	
	for(int i=1;i<=N;i++)
	{
		int	c;
		
		cin>>c;
		coin.push_back(c);
		dp[c] = 1;
	}
	
	cout<<get_dp(dp,C,coin)<<'\n';
	
	return	0;
}
