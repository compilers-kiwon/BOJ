#include	<iostream>
#include	<queue>

using namespace	std;

void	count_items(int num_of_items,priority_queue<int>& pq,int& total_price)
{
	for(int i=1;i<=num_of_items;i++)
	{
		int	p;
		
		cin>>p;
		
		pq.push(p);
		total_price += p;
	}
}

int		main(void)
{
	int	B,C,D;
	int	total_price,discounted;
	
	priority_queue<int>	bugger,side,drink;
	
	cin>>B>>C>>D;
	total_price = discounted = 0;
	
	count_items(B,bugger,total_price);
	count_items(C,side,total_price);
	count_items(D,drink,total_price);
	
	for(int i=1;i<=min(min(B,C),D);i++)
	{
		discounted += bugger.top()/10;
		discounted += side.top()/10;
		discounted += drink.top()/10;
		
		bugger.pop();side.pop();drink.pop();
	}
	
	cout<<total_price<<'\n'<<total_price-discounted<<'\n';
	
	return	0;
}
