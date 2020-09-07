#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	int			N,M,max_profit,max_profit_price;
	vector<int>	P;
	
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	p;
		
		cin>>p;
		P.push_back(p);
	}
	
	sort(P.begin(),P.end());
	
	max_profit = 0;
	
	for(int i=0;i<M;i++)
	{
		int current_profit;
		
		current_profit = min(N,M-i)*P[i];
		
		if( max_profit < current_profit )
		{
			max_profit = current_profit;
			max_profit_price = P[i];
		}
	}
	cout<<max_profit_price<<' '<<max_profit<<endl;
	
	return	0;
}
