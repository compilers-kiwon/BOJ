#include	<cstdio>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CITY	(1000+1)

typedef	pair<int,int>	Bus;

vector<Bus>	bus_info[MAX_NUM_OF_CITY];
vector<int>	cost_table(MAX_NUM_OF_CITY,0x7FFFFFFF);

void	update_cost(int from,int to)
{
	priority_queue<Bus>	pq;	// first:cost,second:to
	
	for(int i=0;i<bus_info[from].size();i++)
	{
		pq.push(bus_info[from][i]);	
	}
	
	while( pq.size() != 0 )
	{
		int	cost,to_city;
		
		cost = -pq.top().first;
		to_city = pq.top().second;
		pq.pop();
		
		if( cost >= cost_table[to_city] )
		{
			continue;
		}
		
		cost_table[to_city] = cost;
		
		for(int i=0;i<bus_info[to_city].size();i++)
		{
			Bus	new_info;
			
			new_info.first = -cost+bus_info[to_city][i].first;
			new_info.second = bus_info[to_city][i].second;
			
			pq.push(new_info);	
		}	
	}	
}

int		main(void)
{
	int	n,m;
	
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=m;i++)
	{
		int	from,to,cost;
		
		scanf("%d %d %d",&from,&to,&cost);
		
		bus_info[from].push_back(make_pair(-cost,to));	
	}
	
	int	from,to;
	
	scanf("%d %d",&from,&to);
	
	update_cost(from,to);
	printf("%d\n",cost_table[to]);
	
	return	0;	
}	
