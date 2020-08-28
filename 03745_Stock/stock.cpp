#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

void	input(int num_of_data,vector<int>& stock_price)
{
	for(int i=1;i<=num_of_data;i++)
	{
		int	p;
		
		scanf("%d",&p);
		stock_price.push_back(p);
	}
}

int		find_lis(vector<int>& stock_price)
{
	vector<int>	lis;
	
	for(int i=0;i<stock_price.size();i++)
	{
		int&	p = stock_price[i];
		
		if( lis.empty() || p>lis.back() )
		{
			lis.push_back(p);
		}
		
		vector<int>::iterator	it;
		
		it = lower_bound(lis.begin(),lis.end(),p);
		*it = p;
	}
	
	return	lis.size();
}

int		main(void)
{
	for(int N;scanf("%d",&N)!=-1;)
	{
		vector<int>	p;
		
		input(N,p);
		printf("%d\n",find_lis(p));
	}
	
	return	0;
}
