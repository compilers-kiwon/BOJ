#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100000+1)

int			N,M;
vector<int>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		connected[a].push_back(b);
		connected[b].push_back(a);
	}
}

int		bfs(void)
{
	queue<int>		q;
	vector<bool>	visited(N+1,false);
	vector<int>		path(N+1);
	
	q.push(1);
	visited[1] = true;
	path[1] = 0;
	
	for(;!q.empty();)
	{
		int	current;
		
		current = q.front();
		q.pop();
		
		if( current == N )
		{
			break;
		}
		
		vector<int>&	adj = connected[current];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_node = adj[i];
			
			if( visited[adj_node] == false )
			{
				visited[adj_node] = true;
				path[adj_node] = path[current]+1;
				q.push(adj_node);
			}
		}
	}
	
	return	path[N]-1;
}

int		main(void)
{
	//cin.tie(NULL);
	//cin.sync_with_stdio(false);
	
	input();
	cout<<bfs()<<'\n';
	
	return	0;
}
