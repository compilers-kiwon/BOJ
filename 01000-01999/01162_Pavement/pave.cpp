#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(10000+1)
#define	MAX_PAVE	(20+1)
#define	INF			0x1000000000

typedef	long long int	int64;

int		N,M,K;
int64	dp[MAX_SIZE][MAX_PAVE];
bool	visited[MAX_SIZE][MAX_PAVE];

typedef	pair<int,int>		Path;		// first:city,second:num_of_paved_road
typedef	pair<int64,Path>	State;		// first:-time,second:Path
typedef	pair<int,int64>		Connected;	// first:adj_city,second:time

vector<Connected>		connected[MAX_SIZE];
priority_queue<State>	pq;

void	input(void)
{
	cin>>N>>M>>K;
	
	for(int i=1;i<=M;i++)
	{
		int		c1,c2;
		int64	t;
		
		cin>>c1>>c2>>t;
		
		connected[c1].push_back(make_pair(c2,t));
		connected[c2].push_back(make_pair(c1,t));
	}
	
	for(int i=1;i<=N;i++)
	{
		fill(&dp[i][0],&dp[i][K+1],INF);
	}
}

int64	find_best_path(void)
{
	int64	ret;
	
	ret = INF;
	pq.push(make_pair(0,make_pair(1,0)));
	
	fill(&dp[1][0],&dp[1][K+1],0);
	
	for(;!pq.empty();)
	{
		int		current_city,current_pave;
		int64	current_time;
		
		current_time = -pq.top().first;
		current_city = pq.top().second.first;
		current_pave = pq.top().second.second;
		
		pq.pop();
		
		if( current_city==N || visited[current_city][current_pave]==true )
		{
			continue;
		}
		
		visited[current_city][current_pave] = true;
		
		vector<Connected>&	adj = connected[current_city];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_city = adj[i].first;
			int64&	adj_time = adj[i].second;
			
			if( current_time+adj_time < dp[adj_city][current_pave] )
			{
				dp[adj_city][current_pave] = current_time+adj_time;
				pq.push(make_pair(-(current_time+adj_time),make_pair(adj_city,current_pave)));
			}
			
			if( current_pave<K && current_time<dp[adj_city][current_pave+1] )
			{
				dp[adj_city][current_pave+1] = current_time;
				pq.push(make_pair(-current_time,make_pair(adj_city,current_pave+1)));
			}
		}
	}
	
	for(int i=0;i<=K;i++)
	{
		ret = min(ret,dp[N][i]);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<find_best_path()<<'\n';
	
	return	0;
}
