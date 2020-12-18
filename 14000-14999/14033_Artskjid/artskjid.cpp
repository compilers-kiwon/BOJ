#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	18
#define	INF			0x7FFFFFFF

typedef	pair<int,int>			Road;	// first:to_city,second:length
typedef	pair<pair<int,int>,int>	State;	// first:<current_city,visited_city>,second:total_length

int				n,m,dp[1<<MAX_SIZE][MAX_SIZE];
vector<Road>	connected[MAX_SIZE];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	s,d,l;
		
		cin>>s>>d>>l;
		connected[s].push_back(make_pair(d,l));
	}
}

int		bfs(void)
{
	queue<State>	state_q;
	int				ret;
	
	for(ret=0,state_q.push(make_pair(make_pair(0,1),0));!state_q.empty();)
	{
		int	current_city,visited_city,current_length;
		
		current_city = state_q.front().first.first;
		visited_city = state_q.front().first.second;
		current_length = state_q.front().second;
		
		state_q.pop();
		
		if( current_city == n-1 )
		{
			ret = max(ret,current_length);
			continue;
		}
		
		for(int i=0;i<connected[current_city].size();i++)
		{
			int&	adj_city = connected[current_city][i].first;
			int&	adj_length = connected[current_city][i].second;
			
			if( (visited_city&(1<<adj_city)) != 0 )
			{
				continue;
			}
			
			State	s;
			
			s.first.second = visited_city|(1<<adj_city);
			
			if( current_length+adj_length > dp[s.first.second][adj_city] )
			{
				s.first.first = adj_city;
				s.second = current_length+adj_length;
				
				state_q.push(s);
				dp[s.first.second][adj_city] = s.second;
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
	cout<<bfs()<<'\n';
	
	return	0;
}
