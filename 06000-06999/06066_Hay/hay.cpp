#include	<iostream>

using namespace	std;

#define	MAX_POUNDS			(50000+1)
#define	MAX_SUPPLIERS		(100+1)
#define	NONE				-1
#define	INF					0x7FFFFFFF

typedef	pair<int,int>	Supplier;	// first:pounds,second:cost

int			N,H,dp[MAX_POUNDS];
Supplier	s[MAX_SUPPLIERS];

int	get_dp(int p)
{
	int&	ret = dp[p];
	
	if( ret != NONE )
	{
		return	ret;
	}
	
	ret = INF;
	
	for(int i=1;i<=N;i++)
	{
		int&	current_pounds = s[i].first;
		int&	current_cost = s[i].second;
		
		ret = min(ret,get_dp(max(0,p-current_pounds))+current_cost);
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>H;
	fill(&dp[1],&dp[H+1],NONE);
	
	for(int i=1;i<=N;i++)
	{
		cin>>s[i].first>>s[i].second;
	}
	
	cout<<get_dp(H)<<'\n';
	
	return	0;
}
