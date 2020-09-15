#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	INF					0x7FFFFFFF
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	MAX_SIZE			(300000+1)

typedef	pair<int,int>	State;	//first:-step,second:station

vector<int>	teleport[MAX_SIZE];

void	move_station(int num_of_stations,int adj_station,
					 int adj_steps,vector<int>& dp,
					 priority_queue<State>& pq)
{
	if( IN_RANGE(1,adj_station,num_of_stations) == false )
	{
		return;
	}
	
	if( adj_steps < dp[adj_station] )
	{
		dp[adj_station] = adj_steps;
		pq.push(make_pair(-adj_steps,adj_station));
	}
}

int		get_min_time(int num_of_stations,int start,
					 int end,vector<int>& dp)
{
	priority_queue<State>	pq;
	
	pq.push(make_pair(0,start));
	dp[start] = 0;
	
	for(;!pq.empty();)
	{
		int	current_steps,current_station;
		
		current_steps = -pq.top().first;
		current_station = pq.top().second;
		
		pq.pop();
		
		if( current_station == end )
		{
			break;
		}
		
		move_station(num_of_stations,current_station-1,current_steps+1,dp,pq);
		move_station(num_of_stations,current_station+1,current_steps+1,dp,pq);
		
		vector<int>&	adj_stations = teleport[current_station];
		
		for(int i=0;i<adj_stations.size();i++)
		{
			move_station(num_of_stations,adj_stations[i],current_steps+1,dp,pq);
		}
	}
	
	return	dp[end];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,M,S,E;
	
	cin>>N>>M>>S>>E;
	
	vector<int>	dp(N+1,INF);

	for(int i=1;i<=M;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		teleport[x].push_back(y);
		teleport[y].push_back(x);
	}
	
	cout<<get_min_time(N,S,E,dp)<<'\n';
	
	return	0;
}
