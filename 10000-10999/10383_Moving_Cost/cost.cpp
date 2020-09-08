#include	<iostream>
#include	<string>
#include	<queue>
#include	<cmath>

using namespace	std;

typedef	pair<string,int>	Product;

void	input(int num_of_products,priority_queue<Product>& pq)
{
	for(int i=1;i<=num_of_products;i++)
	{
		string	p;
		
		cin>>p;
		pq.push(make_pair(p,i));
	}
}

int		get_cost(int num_of_products,priority_queue<Product>& pq)
{
	int	total_cost;
	
	for(total_cost=0;num_of_products>0;num_of_products--)
	{
		int	index;
		
		index = pq.top().second;
		total_cost += abs(num_of_products-index);
		
		pq.pop();
	}
	
	return	total_cost;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int i=1;;i++)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		priority_queue<Product>	product_pq;
		
		input(n,product_pq);
		cout<<"Site "<<i<<": "<<get_cost(n,product_pq)<<'\n';
	}
	
	return	0;
}
