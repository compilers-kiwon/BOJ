#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(500+1)
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	Path;	// first:to,scond:length
typedef	pair<int,int>	State;	// first:-length,second:intersection

int				f,i;
bool			is_fire_station[MAX_SIZE];
vector<Path>	connected[MAX_SIZE];
vector<int>		fire_station;

void	input(void)
{
	scanf("%d %d",&f,&i);
	
	for(int n=1;n<=f;n++)
	{
		int	s;
		
		scanf("%d",&s);
		
		fire_station.push_back(s);
		is_fire_station[s] = true;
	}
	
	for(int a,b,c;scanf("%d %d %d",&a,&b,&c)!=-1;)
	{
		connected[a].push_back(make_pair(b,c));
		connected[b].push_back(make_pair(a,c));
	}
}

int		get_max_distance(void)
{
	vector<int>				dp(i+1,INF);
	priority_queue<State>	pq;
	
	for(int n=0;n<fire_station.size();n++)
	{
		dp[fire_station[n]] = 0;
		pq.push(make_pair(0,fire_station[n]));
	}
	
	for(;!pq.empty();)
	{
		int	current_intersection,current_length;
		
		current_length = -pq.top().first;
		current_intersection = pq.top().second;
		
		pq.pop();
		
		if( current_length > dp[current_intersection] )
		{
			continue;
		}
		
		vector<Path>&	adj = connected[current_intersection];
		
		for(int n=0;n<adj.size();n++)
		{
			int&	adj_intersection = adj[n].first;
			int&	adj_length = adj[n].second;
			
			if( current_length+adj_length < dp[adj_intersection] )
			{
				dp[adj_intersection] = current_length+adj_length;
				pq.push(make_pair(-(current_length+adj_length),adj_intersection));
			}
		}
	}
	
	int	max_length;
	
	max_length = 0;
	
	for(int n=1;n<=i;n++)
	{
		max_length = max(max_length,dp[n]);
	}
	
	return	max_length;
}

int		main(void)
{
	int	minimized_max_length,new_fire_station;
	
	input();
	
	minimized_max_length = INF;
	new_fire_station = 1;
	
	for(int n=1;n<=i;n++)
	{
		if( is_fire_station[n] == false )
		{
			int	tmp;
			
			fire_station.push_back(n);
			tmp = get_max_distance();
			
			if( tmp < minimized_max_length )
			{
				minimized_max_length = tmp;
				new_fire_station = n;
			}
			
			fire_station.pop_back();
		}
	}
	
	printf("%d\n",new_fire_station);
	
	return	0;
}
