#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(300000+1)

int			N;
bool		visited[MAX_SIZE];
vector<int>	connected[MAX_SIZE];

void	bfs(int s)
{
	queue<int>	q;
	
	q.push(s);
	visited[s] = true;
	
	for(;!q.empty();)
	{
		int	current;
		
		current = q.front();
		q.pop();
		
		for(int i=0;i<connected[current].size();i++)
		{
			int&	adj = connected[current][i];
			
			if( visited[adj] == false )
			{
				q.push(adj);
				visited[adj] = true;
			}
		}
	}
}

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N-2;i++)
	{
		int	u,v;
		
		cin>>u>>v;
		
		connected[u].push_back(v);
		connected[v].push_back(u);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	bfs(1);
	
	for(int i=1;i<=N;i++)
	{
		if( visited[i] == false )
		{
			cout<<"1 "<<i<<'\n';
			break;
		}
	}
	
	return	0;
}
