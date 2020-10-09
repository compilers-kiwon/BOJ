#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(20000+1)

#define	NO_COLOR	-1
#define	COLOR_1		0
#define	COLOR_2		1
#define	MAX_COLOR	2

#define	adj_color(c)	(((c)+1)%MAX_COLOR)

typedef	vector<int>	Connected;

void	input(int& num_of_v,int& num_of_e,vector<Connected>& graph)
{
	cin>>num_of_v>>num_of_e;
	graph.resize(num_of_v+1);
	
	for(int i=1;i<=num_of_e;i++)
	{
		int	u,v;
		
		cin>>u>>v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

bool	bfs(int s,vector<Connected>& graph,vector<int>& color)
{
	queue<int>	q;
	
	q.push(s);
	color[s] = COLOR_1;
	
	for(;!q.empty();)
	{
		int	current;
		
		current = q.front();
		q.pop();
		
		Connected&	adj = graph[current];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_v = adj[i];
			
			if( color[current] == color[adj_v] )
			{
				return	false;
			}
			
			if( color[adj_v] == adj_color(color[current]) )
			{
				continue;
			}
			
			q.push(adj_v);
			color[adj_v] = adj_color(color[current]);
		}
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int					V,E;
		bool				result;
		vector<Connected>	g;
		vector<int>			c;
		
		input(V,E,g);
		c.resize(V+1,NO_COLOR);
		
		result = true;
		
		for(int i=1;i<=V&&result!=false;i++)
		{
			if( c[i] == NO_COLOR )
			{
				result = bfs(i,g,c);
			}
		}
		
		if( result == true )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return	0;
}
