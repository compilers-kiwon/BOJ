#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX_EDGE	(100000+1)
#define	MAX_QUERY	(200000+1)

#define	INF		0x10000000
#define	NONE	0

typedef	pair<int,int>	Path;	// first:from,second:to
typedef	pair<int,Path>	Edge;	// first:length,second:path
typedef	pair<char,int>	Query;	// first:operation,second:num

int			N,M,Q,d[MAX_SIZE];
vector<int>	connected[MAX_SIZE];
Edge		e[MAX_EDGE];
Query		q[MAX_QUERY];

void	input(void)
{
	cin>>N>>M>>Q;
	fill(&d[1],&d[N+1],INF);
	
	for(int i=1;i<=M;i++)
	{
		int&	u = e[i].second.first;
		int&	v = e[i].second.second;
		
		cin>>u>>v;
		e[i].first = 1;
	}
	
	for(int i=1;i<=Q;i++)
	{
		char&	t = q[i].first;
		int&	p = q[i].second;
		
		cin>>t>>p;
		
		if( t == 'U' )
		{
			e[p].first = NONE;
		}
	}
}

void	update_graph(int s,int new_distance)
{
	queue<int>	q;
	
	d[s] = new_distance;
	q.push(s);
	
	for(;!q.empty();)
	{
		int	current;
		
		current = q.front();
		q.pop();
		
		vector<int>&	adj = connected[current];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_node = adj[i];
			int&	adj_distance = d[adj_node];
			
			if( d[current]+1 < adj_distance )
			{
				adj_distance = d[current]+1;
				q.push(adj_node);
			}
		}
	}
}

void	build_graph(void)
{
	for(int i=1;i<=M;i++)
	{		
		int&	length = e[i].first;
		int&	u = e[i].second.first;
		int&	v = e[i].second.second;
		
		if( length != NONE )
		{
			connected[u].push_back(v);
		}
	}
	
	update_graph(1,0);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	build_graph();
	
	vector<int>	result;
	
	for(int i=Q;i>=1;i--)
	{
		char&	t = q[i].first;
		int&	p = q[i].second;
		
		switch(t)
		{
			case	'U':
			{
				int&	u = e[p].second.first;
				int&	v = e[p].second.second;
				
				connected[u].push_back(v);
				
				if( d[u]!=INF && d[u]+1<d[v] )
				{
					update_graph(v,d[u]+1);
				}
				
				break;
			}
			case	'E':
			{
				if( d[p] == INF )
				{
					result.push_back(-1);
				}
				else
				{
					result.push_back(d[p]);
				}
				
				break;
			}
			default:
				// do nothing
				break;
		}
	}
	
	for(int i=result.size()-1;i>=0;i--)
	{
		cout<<result[i]<<'\n';
	}
	
	return	0;
}
