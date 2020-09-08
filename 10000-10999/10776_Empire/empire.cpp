#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE		(2000+1)
#define	MAX_THICKNESS	(200+1)
#define	INF				0x7FFFFFFF

typedef	pair<int,int>	Raft;	// first:Island, second:thickness
typedef	pair<int,Raft>	State;	// first:-time, second:Raft

typedef	pair<int,int>	Map;	// first:t, second:h
typedef	pair<int,Map>	Path;	// first:island, second:Map

int				K,N,M,A,B;
int				dp[MAX_SIZE][MAX_THICKNESS];
vector<Path>	connected[MAX_SIZE];

void	input(void)
{
	cin>>K>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	t,h;
		
		cin>>A>>B>>t>>h;
		
		connected[A].push_back(make_pair(B,make_pair(t,h)));
		connected[B].push_back(make_pair(A,make_pair(t,h)));
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=K;j++)
		{
			dp[i][j] = INF;
		}
	}
	
	cin>>A>>B;
	
	for(int i=1;i<=K;i++)
	{
		dp[A][i] = 0;
	}
}

int		get_min_time(void)
{
	priority_queue<State>	pq;
	
	pq.push(make_pair(0,make_pair(A,K)));
	
	for(;!pq.empty();)
	{
		int	current_time,current_island,current_thickness;
		
		current_time = -pq.top().first;
		current_island = pq.top().second.first;
		current_thickness = pq.top().second.second;
		
		pq.pop();
		
		if( current_island == B )
		{
			return	current_time;
		}
		
		vector<Path>&	adj = connected[current_island];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_island = adj[i].first;
			int&	adj_t = adj[i].second.first;
			int&	adj_h = adj[i].second.second;
			int		adj_thickness = current_thickness-adj_h;
			
			if( adj_thickness>0 && current_time+adj_t<dp[adj_island][adj_thickness] )
			{
				dp[adj_island][adj_thickness] = current_time+adj_t;
				pq.push(make_pair(-(current_time+adj_t),make_pair(adj_island,adj_thickness)));
			}
		}
	}
	
	return	-1;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_min_time()<<'\n';
	
	return	0;
}
