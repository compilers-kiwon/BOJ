#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CITY		(1000+1)
#define	MAX_NUM_OF_INCREASE	(30000+1)

typedef	pair<int,int>	Prev;	// first: current_city, second: number of visited city
typedef	pair<int,Prev>	State;	
typedef	pair<int,int>	Path;	// first:to_city, second:cost

int		N,M,K,S,D;
int		dp[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];

vector<Path>	connected[MAX_NUM_OF_CITY];

void	find_min_cost(void)
{
	priority_queue<State>	pq;
	
	pq.push(make_pair(0,make_pair(S,0)));
	
	for(int i=0;i<=N;i++)
	{
		dp[S][i] = 0;
	}
		
	while( !pq.empty() )
	{
		int	current_cost,current_city,current_num_of_visited_city;
		
		current_cost = -pq.top().first;
		current_city = pq.top().second.first;
		current_num_of_visited_city = pq.top().second.second;
		
		pq.pop();
		
		if( current_cost > dp[current_city][current_num_of_visited_city] )
		{
			continue;
		}
		
		vector<Path>&	to_city = connected[current_city];
		
		for(int i=0;i<to_city.size();i++)
		{
			int&	adj_city = to_city[i].first;
			int		adj_cost = current_cost+to_city[i].second;
			int		adj_num_of_visited_city = current_num_of_visited_city+1;
			
			if( adj_cost < dp[adj_city][adj_num_of_visited_city] )
			{
				dp[adj_city][adj_num_of_visited_city] = adj_cost;
				pq.push(make_pair(-adj_cost,make_pair(adj_city,adj_num_of_visited_city)));
			}
		}
	}
}

void	input(void)
{
	scanf("%d %d %d %d %d",&N,&M,&K,&S,&D);
	
	for(int i=1;i<=M;i++)
	{
		int	a,b,w;
		
		scanf("%d %d %d",&a,&b,&w);
		
		connected[a].push_back(make_pair(b,w));
		connected[b].push_back(make_pair(a,w));
	}	
}

int		main(void)
{
	input();
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dp[i][j] = 1000000000;
		}
	}
	
	find_min_cost();
	
	int	min_cost;
	
	min_cost = dp[D][0];
	
	for(int i=1;i<=N;i++)
	{
		min_cost = min(min_cost,dp[D][i]);
	}
	
	printf("%d\n",min_cost);
	
	for(int i=1;i<=K;i++)
	{
		int	p;
		
		scanf("%d",&p);
		min_cost = 0x7FFFFFFF;
					
		for(int j=1;j<=N;j++)
		{
			dp[D][j] += p*j;
			min_cost = min(min_cost,dp[D][j]);
		}
		
		printf("%d\n",min_cost);
	}
	
	return	0;
}
