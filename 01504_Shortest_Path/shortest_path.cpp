#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_V	(800+1)

typedef	pair<int,int>	State;	// first:-cost,second:current_v
typedef	pair<int,int>	Edge;	// first:to_v,second:cost

int				N,E,v1,v2;
vector<Edge>	G[MAX_NUM_OF_V];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>E;
	
	for(int i=1;i<=E;i++)
	{
		int	a,b,c;
		
		cin>>a>>b>>c;
		
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
	}
	
	cin>>v1>>v2;
}

int		find_shortest_path(int from,int to)
{
	vector<int>				dp(N+1,0x7FFFFFFF);
	priority_queue<State>	pq;
	
	pq.push(make_pair(0,from));
	dp[from] = 0;
	
	while( !pq.empty() )
	{
		int	current_v,current_cost;
		
		current_cost = -pq.top().first;
		current_v = pq.top().second;
		
		pq.pop();
		
		if( current_v == to )
		{
			break;
		}
		
		vector<Edge>& adj = G[current_v];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_v = adj[i].first;
			int		adj_cost = adj[i].second+current_cost;
			
			if( adj_cost < dp[adj_v] )
			{
				dp[adj_v] = adj_cost;
				pq.push(make_pair(-adj_cost,adj_v));
			}
		}
	}
	
	return	dp[to];
}

int		main(void)
{
	init();
	
	int		p1,p2,tmp;
	
	p1 = p2 = 0;
	
	// 1->v1->v2->N
	tmp = find_shortest_path(1,v1);
	
	if( tmp == 0x7FFFFFFF )
	{
		cout<<-1<<'\n';
		return	0;
	}
	
	p1 += tmp;
	
	tmp = find_shortest_path(v1,v2);
	
	if( tmp == 0x7FFFFFFF )
	{
		cout<<-1<<'\n';
		return	0;
	}
	
	p1 += tmp;
	
	tmp = find_shortest_path(v2,N);
	
	if( tmp == 0x7FFFFFFF )
	{
		cout<<-1<<'\n';
		return	0;
	}
	
	p1 += tmp;
	
	// 1->v2->v1->N
	tmp = find_shortest_path(1,v2);
	
	if( tmp == 0x7FFFFFFF )
	{
		cout<<-1<<'\n';
		return	0;
	}
	
	p2 += tmp;
	
	tmp = find_shortest_path(v2,v1);
	
	if( tmp == 0x7FFFFFFF )
	{
		cout<<-1<<'\n';
		return	0;
	}
	
	p2 += tmp;
	
	tmp = find_shortest_path(v1,N);
	
	if( tmp == 0x7FFFFFFF )
	{
		cout<<-1<<'\n';
		return	0;
	}
	
	p2 += tmp;
	
	cout<<min(p1,p2)<<'\n';
	
	return	0;
}
