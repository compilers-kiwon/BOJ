#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

using namespace std;

#define	MAX_NUM_OF_VERTEX	(1000+1)

vector<int>		graph[MAX_NUM_OF_VERTEX];
vector<bool>	dfs_visited(MAX_NUM_OF_VERTEX,false);
vector<bool>	bfs_visited(MAX_NUM_OF_VERTEX,false);

void	dfs(int v)
{
	cout<<v<<' ';
		
	for(int i=0;i<graph[v].size();i++)
	{
		int	next_v = graph[v][i];
		
		if( dfs_visited[next_v] == false )
		{
			dfs_visited[next_v] = true;
			dfs(next_v);
		}
	}
}

void	bfs(int v)
{
	queue<int>	vq;
	
	vq.push(v);
	
	while( vq.size() != 0 )
	{
		int	next_v = vq.front();
		vq.pop();
		
		for(int i=0;i<graph[next_v].size();i++)
		{
			int	vertex = graph[next_v][i];
			
			if( bfs_visited[vertex] == false )
			{
				bfs_visited[vertex] = true;
				vq.push(vertex);
			}
		}
		cout<<next_v<<' ';
	}
}

int		main(void)
{
	int	N,M,V,i;
	
	cin>>N>>M>>V;
	
	for(i=1;i<=M;i++)
	{
		int	v1,v2;
		
		cin>>v1>>v2;
		
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	
	for(i=1;i<=N;i++)
	{
		sort(graph[i].begin(),graph[i].end());
	}
	
	dfs_visited[V] = true;
	dfs(V);
	cout<<endl;
	
	bfs_visited[V] = true;
	bfs(V);
	cout<<endl;
	
	return	0;
}
