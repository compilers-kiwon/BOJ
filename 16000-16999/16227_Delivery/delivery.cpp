#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SAND			100
#define	MAX_NUM_OF_CLEANER	(1000+1)

typedef	pair<int,int>	Path;	// first:to, second:time
typedef	pair<int,int>	Car;	// first:pos, second:sand
typedef	pair<int,Car>	State;	// first:time, second: Car

int				N,K,dp[MAX_NUM_OF_CLEANER+1][MAX_SAND+1];
vector<Path>	connected[MAX_NUM_OF_CLEANER+1];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	u,v,t;
		
		cin>>u>>v>>t;
		
		connected[u].push_back(make_pair(v,t));
		connected[v].push_back(make_pair(u,t));
	}
}

int		find_min_time(void)
{
	queue<State>	state_q;
	Car				c;
	int				min_time;
	
	state_q.push(make_pair(0,make_pair(0,0)));
	
	for(min_time=0x7FFFFFFF;!state_q.empty();)
	{
		int	current_time,current_pos,current_sand;
		
		current_time = state_q.front().first;
		current_pos = state_q.front().second.first;
		current_sand = state_q.front().second.second;

		state_q.pop();
		
		if( current_pos == N+1 )
		{
			min_time = min(min_time,current_time);
			continue;
		}
		
		vector<Path>&	adj_path = connected[current_pos];
		
		for(int i=0;i<adj_path.size();i++)
		{
			int&	adj_pos = adj_path[i].first;
			int&	adj_time = adj_path[i].second;
			
			if( adj_pos!=0 && adj_time<=MAX_SAND )
			{
				int	next_sand,next_time;
				
				next_sand = current_sand+adj_time;
				next_time = current_time+adj_time;
				
				if( next_sand<=MAX_SAND && (dp[adj_pos][next_sand]==0||next_time<dp[adj_pos][next_sand]) )
				{
					dp[adj_pos][next_sand] = next_time;
					state_q.push(make_pair(next_time,make_pair(adj_pos,next_sand)));
				}
				
				next_sand = adj_time;
				next_time += 5;
				
				if( dp[adj_pos][next_sand]==0 || next_time<dp[adj_pos][next_sand] )
				{
					dp[adj_pos][next_sand] = next_time;
					state_q.push(make_pair(next_time,make_pair(adj_pos,next_sand)));
				}
			}
		}
	}
	
	return	min_time;
}

int		main(void)
{
	init();
	cout<<find_min_time()<<'\n';
	
	return	0;
}
