#include	<iostream>

using namespace std;

#define	MAX_NUM_OF_CITY	(100000+1)

typedef	unsigned long long	uint64;
typedef	unsigned int		uint32;

int		N;
uint64	dist[MAX_NUM_OF_CITY-1];	// (i)th = from (i)th to (i+1)th
uint64	price[MAX_NUM_OF_CITY];
uint64	total_cost;

int	main(void)
{
	int		i;
	uint32	min_price;
	
	cin>>N;
	
	for(i=1;i<N;i++)
	{
		cin>>dist[i];
	}
	
	total_cost = 0;
	min_price = 0xFFFFFFFF;
	
	for(i=1;i<N;i++)
	{
		cin>>price[i];
		
		if( price[i] < min_price )
		{
			min_price = price[i];
		}
		
		total_cost = total_cost+(min_price*dist[i]);	
	}
	cin>>price[i];
	
	cout<<total_cost<<endl;
	
	return	0; 
}

