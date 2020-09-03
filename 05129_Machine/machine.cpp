#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_MACHINES	(20+1)
#define	MAX_SIZE_OF_NETWORK	(100+1)

#define	INF	0x7FFFFFFF

typedef	pair<int,int>	Wormhole;	// first:to,second:time
typedef	pair<int,int>	State;		// first:-time,second:current_location
typedef	pair<int,int>	Query;		// first:start,second:time

int					M,N,W,destination[MAX_NUM_OF_MACHINES];
bool				visited[MAX_SIZE_OF_NETWORK];
Query				q[MAX_NUM_OF_MACHINES];
vector<int>			dst_candidates[MAX_NUM_OF_MACHINES];
vector<Wormhole>	connected[MAX_SIZE_OF_NETWORK];

bool	all_candidates_are_visited(void)
{
	for(int i=1;i<=M;i++)
	{
		vector<int>&	c = dst_candidates[i];
		
		for(int j=0;j<c.size();j++)
		{
			if( visited[c[j]] == false )
			{
				return	false;
			}
		}
	}
	
	return	true;
}

bool	dfs(int current_machine)
{
	if( current_machine > M )
	{
		return	all_candidates_are_visited();
	}
	
	vector<int>&	c = dst_candidates[current_machine];
	
	for(int i=0;i<c.size();i++)
	{
		if( visited[c[i]] == false )
		{
			visited[c[i]] = true;
			destination[current_machine] = c[i];
			
			if( dfs(current_machine+1) == true )
			{
				return	true;
			}
			
			visited[c[i]] = false;
		}
	}
	
	return	false;
}

void	get_wormholes(void)
{
	for(int i=1;i<=W;i++)
	{
		int	a,b,c;
		
		cin>>a>>b>>c;
		
		connected[a].push_back(make_pair(b,c));
		connected[b].push_back(make_pair(a,c));
	}
}

void	get_query(void)
{
	for(int i=1;i<=M;i++)
	{
		cin>>q[i].first>>q[i].second;
	}
}

void	input(void)
{
	cin>>M>>N>>W;
	
	get_wormholes();
	get_query();
}

void	find_destination_candidate(int machine)
{
	int						upper_time;
	vector<int>				dp(N+1,INF);
	priority_queue<State>	pq;
	
	dp[q[machine].first] = 0;
	upper_time = q[machine].second;
	pq.push(make_pair(0,q[machine].first));
	
	for(;!pq.empty();)
	{
		int	current_location,current_time;
		
		current_time = -pq.top().first;
		current_location = pq.top().second;
		
		pq.pop();
		
		if( current_time >= upper_time )
		{
			continue;
		}
		
		vector<Wormhole>&	adj = connected[current_location];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_location = adj[i].first;
			int&	adj_time = adj[i].second;
			
			if( current_time+adj_time < dp[adj_location] )
			{
				dp[adj_location] = current_time+adj_time;
				pq.push(make_pair(-(current_time+adj_time),adj_location));
			}
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		if( dp[i] == upper_time )
		{
			dst_candidates[machine].push_back(i);
		}
	}
}

void	init(void)
{
	for(int i=1;i<=MAX_SIZE_OF_NETWORK;i++)
	{
		connected[i].clear();
		visited[i] = false;
	}
	
	for(int i=1;i<=MAX_NUM_OF_MACHINES;i++)
	{
		dst_candidates[i].clear();
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		init();		
		input();
						
		for(int i=1;i<=M;i++)
		{
			find_destination_candidate(i);
		}
		
		cout<<"Data Set "<<k<<":\n";
		
		if( dfs(1) == false )
		{
			cout<<"impossible\n\n";
		}
		else
		{
			for(int i=1;i<M;i++)
			{
				cout<<destination[i]<<' ';
			}
			cout<<destination[M]<<"\n\n";
		}
	}
	
	return	0;
}
