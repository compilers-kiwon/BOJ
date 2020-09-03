#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CITY	1000
#define	MAX_CAPACITY	100
#define	INF				0x7FFFFFFF

typedef	pair<int,int>	Car;	// first:city, second:gas
typedef	pair<int,Car>	State;	// first:-money, second:Car
typedef	pair<int,int>	Road;	// first:city, second:distance

int				n,m,q,p[MAX_NUM_OF_CITY];
int				dp[MAX_NUM_OF_CITY][MAX_CAPACITY+1];
vector<Road>	connected[MAX_NUM_OF_CITY];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	
	for(int i=1;i<=m;i++)
	{
		int	u,v,d;
		
		cin>>u>>v>>d;
		
		connected[u].push_back(make_pair(v,d));
		connected[v].push_back(make_pair(u,d));
	}
}

void	init(int fuel_capacity)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=fuel_capacity;j++)
		{
			dp[i][j] = INF;
		}
	}
}

int		find_cheapest_trip(int fuel_capacity,int start_city,int end_city)
{
	init(fuel_capacity);
	
	priority_queue<State>	pq;
	
	dp[start_city][0] = 0;
	pq.push(make_pair(0,make_pair(start_city,0)));
	
	for(;!pq.empty();)
	{
		int	current_money,current_city,current_fuel;
		
		current_money = -pq.top().first;
		current_city = pq.top().second.first;
		current_fuel = pq.top().second.second;
		
		pq.pop();
		
		if( current_city == end_city )
		{
			return	current_money;
		}
		
		if( current_fuel < fuel_capacity )
		{
			if( current_money+p[current_city] < dp[current_city][current_fuel+1] )
			{
				dp[current_city][current_fuel+1] = current_money+p[current_city];
				pq.push(make_pair(-(current_money+p[current_city]),
								  make_pair(current_city,current_fuel+1)));
			}
		}
		
		vector<Road>&	adj = connected[current_city];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_city = adj[i].first;
			int&	adj_distance = adj[i].second;
						
			if( current_fuel>=adj_distance && current_money<dp[adj_city][current_fuel-adj_distance] )
			{
				dp[adj_city][current_fuel-adj_distance] = current_money;
				pq.push(make_pair(-current_money,make_pair(adj_city,current_fuel-adj_distance)));
			}	
		}
	}
	
	return	INF;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	cin>>q;
	
	for(int i=1;i<=q;i++)
	{
		int c,s,e,cheap;
		
		cin>>c>>s>>e;
		cheap = find_cheapest_trip(c,s,e);
		
		if( cheap == INF )
		{
			cout<<"impossible\n";
		}
		else
		{
			cout<<cheap<<'\n';
		}
	}
	
	return	0;
}
