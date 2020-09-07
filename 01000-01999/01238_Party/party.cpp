#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Path;	// first:to,second:time
typedef	pair<int,int>	State;	// first:-time,second:village

#define	MAX_SIZE	(1000+1)
#define	INF			0x7FFFFFFF

int				N,M,X;
vector<Path>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N>>M>>X;
	
	for(int i=1;i<=M;i++)
	{
		int	from,to,time;
		
		cin>>from>>to>>time;
		connected[from].push_back(make_pair(to,time));
	}
}

int		get_shortest_path_time(int from,int to)
{
	priority_queue<State>	pq;
	vector<int>				dp(N+1,INF);
	int						ret;
	
	dp[from] = 0;
	pq.push(make_pair(0,from));
	
	for(;!pq.empty();)
	{
		int	current_time,current_village;
		
		current_time = -pq.top().first;
		current_village = pq.top().second;
		
		pq.pop();
		
		if( current_village == to )
		{
			ret = current_time;
			break;
		}
		
		vector<Path>&	adj = connected[current_village];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_v = adj[i].first;
			int&	adj_t = adj[i].second;
			
			if( current_time+adj_t < dp[adj_v] )
			{
				dp[adj_v] = current_time+adj_t;
				pq.push(make_pair(-(current_time+adj_t),adj_v));
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
	
	int	max_time;
	
	max_time = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	t;
		
		t = get_shortest_path_time(i,X)+get_shortest_path_time(X,i);
		max_time = max(max_time,t);
	}
	
	cout<<max_time<<'\n';
	
	return	0;
}
