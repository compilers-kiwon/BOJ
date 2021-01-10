#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(2500+1)
#define	MAX_PRICE	(2500+1)
#define	INF			0x7FFFFFFFFFFFFFFF

typedef	long long int		int64;
typedef	pair<int,int64>		Path;	// first:city, second:distance
typedef	pair<int,int64>		State;	// first:city, second:min_oil_price
typedef	pair<int64,State>	Travel;	// first:-cost, second:State

int				N,M;
int64			dp[MAX_SIZE][MAX_PRICE];
int64			oil[MAX_SIZE];
int64			price_table[MAX_SIZE];
vector<Path>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>oil[i];
		fill(&dp[i][1],&dp[i][MAX_PRICE],INF);
	}
	
	fill(&price_table[1],&price_table[MAX_PRICE],INF);
	
	for(int i=1;i<=M;i++)
	{
		int		u,v;
		int64	d;
		
		cin>>u>>v>>d;
		
		connected[u].push_back(make_pair(v,d));
		connected[v].push_back(make_pair(u,d));
	}
}

int64	travel(void)
{
	priority_queue<Travel>	q;
	
	dp[1][oil[1]] = 0;
	price_table[1] = oil[1];
	q.push(make_pair(0,make_pair(1,oil[1])));
	
	int64	ret;
	
	for(ret=INF;!q.empty();)
	{
		int64	current_cost,current_min_oil_price;
		int		current_city;
		
		current_cost = -q.top().first;
		current_city = q.top().second.first;
		current_min_oil_price = q.top().second.second;
		
		q.pop();
		
		if( current_city == N )
		{
			ret = current_cost;
			break;
		}
		
		vector<Path>&	adj = connected[current_city];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_city = adj[i].first;
			int64&	adj_distance = adj[i].second;
			int64	adj_cost,adj_min_oil_price;
			
			adj_cost = current_cost+current_min_oil_price*adj_distance;
			adj_min_oil_price = min(current_min_oil_price,oil[adj_city]);
			
			if( adj_min_oil_price > price_table[adj_city] )
			{
				continue;
			}
			
			price_table[adj_city] = adj_min_oil_price;
			
			if( adj_cost < dp[adj_city][adj_min_oil_price] )
			{
				dp[adj_city][adj_min_oil_price] = adj_cost;
				q.push(make_pair(-adj_cost,make_pair(adj_city,adj_min_oil_price)));
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<travel()<<'\n';
	
	return	0;
}
