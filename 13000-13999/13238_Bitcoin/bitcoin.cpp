#include	<iostream>

using namespace	std;

#define	MAX_DAYS	(100000+1)

int	N,exchange_rate[MAX_DAYS],min_rate[MAX_DAYS];

int	main(void)
{
	int	max_profit;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	min_rate[0] = 0x7FFFFFFF;
	max_profit = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>exchange_rate[i];
		min_rate[i] = min(min_rate[i-1],exchange_rate[i]);
		
		if( exchange_rate[i] > min_rate[i] )
		{
			max_profit = max(max_profit,exchange_rate[i]-min_rate[i]);
		}
	}
	
	cout<<max_profit<<'\n';
	
	return	0;
}
