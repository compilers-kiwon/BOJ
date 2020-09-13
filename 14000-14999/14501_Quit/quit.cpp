#include	<iostream>

using namespace	std;

#define	MAX_DAY	(15+1)

pair<int,int>	schedule[MAX_DAY];	// first:time, second;profit
int				dp[MAX_DAY];

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>schedule[i].first>>schedule[i].second;
	}
	
	dp[1] = schedule[1].second;
	
	for(int i=2;i<=N;i++)
	{
		int	max_profit = 0;
		
		for(int j=1;j<N;j++)
		{
			if( schedule[j].first+j <= i )
			{
				max_profit = max(max_profit,dp[j]);
			}
		}
		dp[i] = max_profit;
		
		if( (schedule[i].first-1)+i <= N )
		{
			dp[i] += schedule[i].second;
		}
	}
	
	int	max_profit = 0;
	
	for(int i=1;i<=N;i++)
	{
		max_profit = max(max_profit,dp[i]);
	}
	cout<<max_profit<<endl;
	
	return	0;
}
