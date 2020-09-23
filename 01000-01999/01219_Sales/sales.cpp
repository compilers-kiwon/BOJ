#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	100
#define	INF			-1000000000000000L

typedef	long long int	int64;
typedef	pair<int,int64>	Path;	// first:to,second:cost

int				N,M,A,B;
int64			profit[MAX_SIZE],dp[MAX_SIZE];
bool			visited[MAX_SIZE];
vector<Path>	connected[MAX_SIZE];
vector<int>		reverse[MAX_SIZE];

void	input(void)
{
	cin>>N>>A>>B>>M;
	
	for(int i=1;i<=M;i++)
	{
		int		u,v;
		int64	c;
		
		cin>>u>>v>>c;
		
		connected[u].push_back(make_pair(v,c));
		reverse[v].push_back(u);
	}
	
	for(int i=0;i<N;i++)
	{
		cin>>profit[i];
		dp[i] = INF;
	}
}

void	find_reachable_city(int current)
{
	if( visited[current] == true )
	{
		return;
	}
	
	visited[current] = true;
	
	for(int i=0;i<reverse[current].size();i++)
	{
		find_reachable_city(reverse[current][i]);
	}
}

bool	travel(void)
{
	bool	infinite;
	
	infinite = false;
	dp[A] = profit[A];
	
	for(int i=1;i<=N;i++)
	{
		bool	update;
		
		update = false;
		
		for(int c=0;c<N;c++)
		{
			int64	current_profit;
			
			current_profit = dp[c];
			
			if( current_profit != INF )
			{
				vector<Path>&	adj = connected[c];
				
				for(int j=0;j<adj.size();j++)
				{
					int&	adj_city = adj[j].first;
					int64&	adj_cost = adj[j].second;
					
					if( visited[adj_city] == false )
					{
						continue;
					}
					
					if( current_profit+profit[adj_city]-adj_cost > dp[adj_city] )
					{
						update = true;
						dp[adj_city] = current_profit+profit[adj_city]-adj_cost;
					}
				}
			}
		}
		
		if( update == false )
		{
			break;
		}
		
		if( i == N )
		{
			infinite = true;
		}
	}
	
	return	infinite;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	bool	infinite;
	
	input();
	find_reachable_city(B);
	
	infinite = travel();
	
	if( dp[B] != INF )
	{
		if( infinite == true )
		{
			cout<<"Gee\n";
		}
		else
		{
			cout<<dp[B]<<'\n';
		}
	}
	else
	{
		cout<<"gg\n";
	}
	
	return	0;
}
