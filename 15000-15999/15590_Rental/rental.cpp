#include	<iostream>
#include	<queue>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100000+1)

typedef	long long int		int64;
typedef	pair<int64,int64>	Store;	// first:price, second:gallon

int		N,M,R;
int64	cow_milk[MAX_SIZE],milk_profit[MAX_SIZE],rent_profit[MAX_SIZE];

priority_queue<Store>	milk_store;
priority_queue<int64>	rent_neighbor;

void	init(void)
{
	cin>>N>>M>>R;
	
	for(int i=1;i<=N;i++)
	{
		cin>>cow_milk[i];
	}
	
	for(int i=1;i<=M;i++)
	{
		int64	g,p;
		
		cin>>g>>p;
		milk_store.push(make_pair(p,g));
	}
	
	for(int i=1;i<=R;i++)
	{
		int64	r;
		
		cin>>r;
		rent_neighbor.push(r);
	}
}

bool	is_bigger(const int64& m1,const int64& m2)
{
	return	(m1>m2);
}

void	get_profit_with_selling_milk(void)
{
	sort(&cow_milk[1],&cow_milk[N+1],is_bigger);
	
	Store	current_store;
	
	current_store = milk_store.top();
	milk_store.pop();
	 
	for(int cow=1;cow<=N;)
	{
		int64	volume;
		
		volume = min(cow_milk[cow],current_store.second);
		
		cow_milk[cow] -= volume;
		current_store.second -= volume;
		milk_profit[cow] += volume*current_store.first;
		
		if( cow_milk[cow] == 0 )
		{
			cow++;
		}
		
		if( current_store.second == 0 )
		{
			if( milk_store.empty() )
			{
				break;
			}
			else
			{
				current_store = milk_store.top();
				milk_store.pop();
			}
		}
	}	
}

void	get_profit_with_rent_cow(void)
{
	for(int cow=N;cow>=1&&!rent_neighbor.empty();cow--,rent_neighbor.pop())
	{
		rent_profit[cow] = rent_neighbor.top();
	}
}

int64	get_max_profit(void)
{
	int64	ret;
	
	ret = 0;
	
	for(int cow=1;cow<=N;cow++)
	{
		ret += max(milk_profit[cow],rent_profit[cow]);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	get_profit_with_selling_milk();
	get_profit_with_rent_cow();
	
	cout<<get_max_profit()<<'\n';
	
	return	0;
}
