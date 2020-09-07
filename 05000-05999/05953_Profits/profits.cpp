#include	<iostream>

using namespace	std;

typedef	long long int	int64;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N;
	int64	P,prev_profit,max_profit;
	
	cin>>N>>P;
	
	max_profit = prev_profit = P;
	
	for(int i=2;i<=N;i++)
	{
		int64	current_profit;
		
		cin>>P;
		
		current_profit = max(P,prev_profit+P);
		max_profit = max(max_profit,current_profit);
		prev_profit = current_profit;
	}
	
	cout<<max_profit<<'\n';

	return	0;
}
