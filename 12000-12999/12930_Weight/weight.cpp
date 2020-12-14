#include	<iostream>
#include	<string>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	20
#define	NONE		0

#define	START_NODE	0
#define	END_NODE	1

#define	char2int(c)	((int)((c)-'0'))

typedef	pair<int,int>	Weight;

int		N,dp[1<<MAX_SIZE][MAX_SIZE];
Weight	connected[MAX_SIZE][MAX_SIZE];

typedef	pair<pair<int,int>,Weight>	Visited;		// first:<all,last>,second:Wegiht
typedef	pair<int,Visited>			State;			// first:-cost,second:Visited

vector<int>	adj[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		string	str;
		
		cin>>str;
		
		for(int j=0;j<N;j++)
		{
			char&	c = str[j];
			
			if( c == '.' )
			{
				continue;
			}
			
			connected[i][j].first = char2int(c);
		}
	}
	
	for(int i=0;i<N;i++)
	{
		string	str;
		
		cin>>str;
		
		for(int j=0;j<N;j++)
		{
			char&	c = str[j];
			
			if( c == '.' )
			{
				continue;
			}
			
			connected[i][j].second = char2int(c);
			adj[i].push_back(j);
		}
	}
}

int		bfs(void)
{
	priority_queue<State>	state_q;
	Visited					v;
	int						ret;
	
	v.first.first = (1<<START_NODE);
	v.first.second = START_NODE;
	v.second = make_pair(0,0);
	
	ret = 0x7FFFFFFF;
	state_q.push(make_pair(0,v));
	
	for(;!state_q.empty();)
	{
		int		current_cost;
		int		all_visited,last_visited;
		Weight	current_weight;
		
		current_cost = -state_q.top().first;
		current_weight = state_q.top().second.second;
		
		all_visited = state_q.top().second.first.first;
		last_visited = state_q.top().second.first.second;
		
		state_q.pop();
		
		if( last_visited == END_NODE )
		{
			ret = current_cost;
			break;
		}
		
		for(int i=0;i<adj[last_visited].size();i++)
		{
			int&	node_idx = adj[last_visited][i];			
			int		adj_node,adj_cost;
			
			adj_node = (1<<node_idx);
			
			if( (all_visited&adj_node)==0 && 
				connected[last_visited][node_idx]!=make_pair(0,0) )
			{
				int&	w1 = current_weight.first;
				int&	w2 = current_weight.second;

				v.first.first = all_visited|adj_node;
				v.first.second = node_idx;
				
				Weight&	tmp = v.second;
				
				tmp = make_pair(w1+connected[last_visited][node_idx].first,
									w2+connected[last_visited][node_idx].second);
				
				if( dp[v.first.first][v.first.second] == NONE ||
					tmp.first*tmp.second < dp[v.first.first][v.first.second] )
				{
					dp[v.first.first][v.first.second] = tmp.first*tmp.second;
					state_q.push(make_pair(-dp[v.first.first][v.first.second],v));
				}
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
		
	int	min_cost;
	
	min_cost = bfs();
	
	if( min_cost == 0x7FFFFFFF )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<min_cost<<'\n';
	}
	
	return	0;
}
