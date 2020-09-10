#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_CITY	(100000+1)
#define	INF				20000000000

typedef	long long int	int64;
typedef	pair<int64,int>	State;	// first:-cost,second:city

int		N,M,K,S;
int64	p,q;
bool	occupied_by_zombi[MAX_NUM_OF_CITY];
bool	is_dangerous[MAX_NUM_OF_CITY];

vector<int>	connected[MAX_NUM_OF_CITY];

void	find_dangerous_city(vector<int>& zombi_city)
{
	queue<int>	dangerous_city_queue;
	
	for(int	i=0;i<zombi_city.size();i++)
	{
		int&	z = zombi_city[i];
		
		is_dangerous[z] = true;
		dangerous_city_queue.push(z);
	}
	
	for(int d=1;d<=S;d++)
	{
		for(int i=1,to=dangerous_city_queue.size();i<=to;i++)
		{
			int	current_city;
			
			current_city = dangerous_city_queue.front();
			dangerous_city_queue.pop();
			
			vector<int>&	adj = connected[current_city];
			
			for(int j=0;j<adj.size();j++)
			{
				int&	adj_city = adj[j];
				
				if( is_dangerous[adj_city] == false )
				{
					is_dangerous[adj_city] = true;
					dangerous_city_queue.push(adj_city);
				}
			}
		}
	}
}

int64	find_min_cost(void)
{
	priority_queue<State>	pq;
	vector<int64>			dp(N+1,INF);
	
	pq.push(make_pair(0,1));
	dp[1] = 0;
	
	while( !pq.empty() )
	{
		int		current_city;
		int64	current_cost;
		
		current_city = pq.top().second;
		current_cost = -pq.top().first;
		pq.pop();
		
		if( current_city == N )
		{
			break;
		}
		
		vector<int>	adj = connected[current_city];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_city = adj[i];
			int64	next_cost;
			
			if( occupied_by_zombi[adj_city] == true )
			{
				continue;
			}
			
			if( adj_city == N )
			{
				next_cost = current_cost;
			}
			else
			{
				if( is_dangerous[adj_city] == true )
				{
					next_cost = current_cost+q;
				}
				else
				{
					next_cost = current_cost+p;
				}
			}
			
			if( next_cost < dp[adj_city] )
			{
				dp[adj_city] = next_cost;
				pq.push(make_pair(-next_cost,adj_city));
			}
		}
	}
	
	return	dp[N];
}

int		main(void)
{
	vector<int>	zombi;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>M>>K>>S>>p>>q;
	
	for(int i=1;i<=K;i++)
	{
		int	c;
		
		cin>>c;
		zombi.push_back(c);
		occupied_by_zombi[c] = true;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	c1,c2;
		
		cin>>c1>>c2;
		
		connected[c1].push_back(c2);
		connected[c2].push_back(c1);
	}
	
	find_dangerous_city(zombi);
	cout<<find_min_cost()<<'\n';
	
	return	0;
}
