#include	<iostream>
#include	<map>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_CITY	(100+1)
#define	MAX_ROAD	(300+1)
#define	NONE		0

int	n,m,s,e;

typedef	pair<int,int>	Road;	// first:cost,second:time
typedef	pair<int,int>	Path;	// first:to_city,second:Road_idx
typedef	pair<int,Road>	State;	// first:current_city,second:<first:current_cost,second:current_time>
				
map<int,int>	dp[MAX_CITY];	// first:cost,second:time
Road			road[MAX_ROAD];
vector<Path>	connected[MAX_CITY];

void	input(void)
{
	cin>>n>>m>>s>>e;
	
	for(int i=1;i<=m;i++)
	{
		int		p,r;
		int&	c = road[i].first;
		int&	t = road[i].second;
		
		cin>>p>>r>>c>>t;
		
		connected[p].push_back(make_pair(r,i));
		connected[r].push_back(make_pair(p,i));
	}
}

bool	is_efficient_path(map<int,int>& p,const int& cost,const int& time)
{
	map<int,int>::iterator	it;
	
	for(it=p.begin();it!=p.end()&&it->first<=cost;it++)
	{
		if( it->second <= time )
		{
			return	false;
		}
	}
	
	return	true;
}

void	find_efficient_path(void)
{
	queue<State>	state_q;
	
	dp[s][0] = 1;
	state_q.push(make_pair(s,make_pair(0,1)));
	
	for(;!state_q.empty();)
	{
		int	current_city,current_cost,current_time;
		
		current_city = state_q.front().first;
		current_cost = state_q.front().second.first;
		current_time = state_q.front().second.second;
		
		state_q.pop();
		
		if( current_city == e )
		{
			continue;
		}
		
		vector<Path>&	adj_path = connected[current_city];
		
		for(int i=0;i<adj_path.size();i++)
		{
			int&	adj_city = adj_path[i].first;
			int&	adj_road = adj_path[i].second;
			int		adj_cost,adj_time;
			
			adj_cost = current_cost+road[adj_road].first;
			adj_time = current_time+road[adj_road].second;
			
			if( is_efficient_path(dp[adj_city],adj_cost,adj_time) == true )
			{
				dp[adj_city][adj_cost] = adj_time;
				state_q.push(make_pair(adj_city,make_pair(adj_cost,adj_time)));
			}
		}
	}
}

int		get_num_of_efficient_path(void)
{
	map<int,int>&	p = dp[e];
	int				min_cost,max_cost,ret;
	
	if( p.size() == 0 )
	{
		return 0;
	}
	
	min_cost = p.begin()->first;
	max_cost = p.rbegin()->first;
	
	ret = 0;
	max_cost++;
	p[max_cost] = NONE;
	
	for(int c1=min_cost;c1<=max_cost-1;c1++)
	{
		if( p[c1] == NONE )
		{
			continue;
		}
		
		for(int c2=c1+1;c2<=max_cost;c2++)
		{
			if( p[c2]==NONE || p[c1]<=p[c2] )
			{
				p[c2] = NONE;
				continue;
			}
		}
		
		ret++;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	find_efficient_path();
	
	cout<<get_num_of_efficient_path()<<'\n';
	
	return	0;
}
