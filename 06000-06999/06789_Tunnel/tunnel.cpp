#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			1600
#define	MAX_EXPOSED_TIME	(3600+1)
#define	INF					0x7FFFFFFF

typedef	pair<int,int>		Path;		// first:to,second:distance
typedef	pair<int,int>		Exposed;	// first:point,second:exposed_time
typedef	pair<int,Exposed>	State;		// first:-time,second:Exposed

int				S,N,E,dp[MAX_SIZE][MAX_EXPOSED_TIME];
vector<Path>	ground[MAX_SIZE],tunnel[MAX_SIZE];

void	input(void)
{
	cin>>S>>N>>E;
	
	for(int i=0;i<N;i++)
	{
		fill(&dp[i][0],&dp[i][S+1],INF);
	}
	
	for(int i=1;i<=E;i++)
	{
		int	s,t,d,u;
		
		cin>>s>>t>>d>>u;
		
		if( u == 1 )
		{
			ground[s].push_back(make_pair(t,d));
			ground[t].push_back(make_pair(s,d));
		}
		else
		{
			tunnel[s].push_back(make_pair(t,d));
			tunnel[t].push_back(make_pair(s,d));
		}
	}
}

int		find_shortest_path(void)
{
	int						ret;
	priority_queue<State>	state_q;
	
	dp[0][0] = 0;
	state_q.push(make_pair(0,make_pair(0,0)));
	
	for(ret=-1;!state_q.empty();)
	{
		int	current_time,current_point,current_exposed_time;
		
		current_time = -state_q.top().first;
		current_point = state_q.top().second.first;
		current_exposed_time = state_q.top().second.second;
		
		state_q.pop();
		
		if( current_point == N-1 )
		{
			ret = current_time;
			break;
		}
		
		// ground
		for(int i=0;i<ground[current_point].size();i++)
		{
			int&	adj_point = ground[current_point][i].first;
			int&	adj_distance = ground[current_point][i].second;
			int		adj_exposed_time;
			
			adj_exposed_time = current_exposed_time+adj_distance;
			
			if( adj_exposed_time>S || current_time+adj_distance>=dp[adj_point][adj_exposed_time] )
			{
				continue;
			}
			
			dp[adj_point][adj_exposed_time] = current_time+adj_distance;
			state_q.push(make_pair(-(current_time+adj_distance),make_pair(adj_point,adj_exposed_time)));
		}
		
		// tunnel
		for(int i=0;i<tunnel[current_point].size();i++)
		{
			int&	adj_point = tunnel[current_point][i].first;
			int&	adj_distance = tunnel[current_point][i].second;
					
			if( current_time+adj_distance >= dp[adj_point][current_exposed_time] )
			{
				continue;
			}
			
			dp[adj_point][current_exposed_time] = current_time+adj_distance;
			state_q.push(make_pair(-(current_time+adj_distance),make_pair(adj_point,current_exposed_time)));
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<find_shortest_path()<<'\n';
	
	return	0;
}
