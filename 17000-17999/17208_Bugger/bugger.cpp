#include	<iostream>

using namespace	std;

#define	MAX_SIZE		(100+1)
#define	MAX_INPUT_SIZE	(300+1)
#define	NONE			-1

typedef	pair<int,int>	Input;	// first:cheese,second:potato

int		N,M,K;
int		dp[MAX_SIZE][MAX_INPUT_SIZE][MAX_INPUT_SIZE];
Input	required_quantity[MAX_SIZE];

int	get_dp(int order_idx,int num_of_available_cheese,int num_of_available_potato)
{
	if( order_idx > N )
	{
		return	0;
	}
	
	int&	ret = dp[order_idx][num_of_available_cheese][num_of_available_potato];
	
	if( ret != NONE )
	{
		return	ret;
	}
	
	ret = get_dp(order_idx+1,num_of_available_cheese,num_of_available_potato);
	
	if( num_of_available_cheese >= required_quantity[order_idx].first 
		&& num_of_available_potato >= required_quantity[order_idx].second )
	{
		int	take_this_order;
		
		take_this_order = get_dp(order_idx+1,
								 num_of_available_cheese-required_quantity[order_idx].first,
								 num_of_available_potato-required_quantity[order_idx].second)+1;
		ret = max(take_this_order,ret);
	}
	
	return	ret;
}

int	main(void)
{
	cin>>N>>M>>K;
	
	for(int i=1;i<=N;i++)
	{
		cin>>required_quantity[i].first>>required_quantity[i].second;
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			fill(&dp[i][j][0],&dp[i][j][K+1],NONE);
		}
	}
	
	cout<<get_dp(1,M,K)<<'\n';
	
	return	0;
}
