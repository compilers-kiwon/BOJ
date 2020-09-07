#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	INF			0x7FFFFFFF

#define	is_pair(a,b,c,d)			((a)==(c)&&(b)==(d))
#define	is_disabled_path(a,b,c,d)	((is_pair((a),(b),(c),(d)))||(is_pair((b),(a),(c),(d))))

typedef	pair<int,int>	Path;	// first:adj_city,second:distance
typedef	pair<int,int>	State;	// first:-distance,second:city

int				N,M,prev_city[MAX_SIZE];
vector<Path>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	x,y,z;
		
		cin>>x>>y>>z;
		
		connected[x].push_back(make_pair(y,z));
		connected[y].push_back(make_pair(x,z));
	}
}

int		find_shortest_path(int c1,int c2,bool initial_path)
{
	priority_queue<State>	pq;
	vector<int>				dp(N+1,INF);
	
	dp[1] = 0;
	pq.push(make_pair(0,1));
	
	for(;!pq.empty();)
	{
		int	current_distance,current_city;
		
		current_distance = -pq.top().first;
		current_city = pq.top().second;
		
		pq.pop();
		
		if( current_city == N )
		{
			break;
		}
		
		vector<Path>&	adj = connected[current_city];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_city = adj[i].first;
			int&	adj_distance = adj[i].second;
			
			if( is_disabled_path(current_city,adj_city,c1,c2) == true )
			{
				continue;
			}
			
			if( current_distance+adj_distance < dp[adj_city] )
			{
				dp[adj_city] = current_distance+adj_distance;
				pq.push(make_pair(-(current_distance+adj_distance),adj_city));
				
				if( initial_path == true )
				{
					prev_city[adj_city] = current_city;
				}
			}
		}
	}
	
	return	dp[N];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	find_shortest_path(0,0,true);
	
	int			maximized_shortest_path;
	vector<int>	visited_city;
	
	for(int i=N;i!=0;i=prev_city[i])
	{
		visited_city.push_back(i);
	}
	
	maximized_shortest_path = 0;
	
	for(int i=0;i<visited_city.size()-1;i++)
	{
		int&	c1 = visited_city[i];
		int&	c2 = visited_city[i+1];
		
		maximized_shortest_path = max(maximized_shortest_path,find_shortest_path(c1,c2,false));
	}
	
	cout<<maximized_shortest_path<<'\n';
	
	return	0;
}
