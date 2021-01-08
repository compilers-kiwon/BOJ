#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(300000+1)
#define	INF			0x7FFFFFFF

int			N,M,K,X,d[MAX_SIZE];
vector<int>	connected[MAX_SIZE];

void	input(void)
{
	cin>>N>>M>>K>>X;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		connected[A].push_back(B);
	}
	
	fill(&d[1],&d[N+1],INF);
}

void	bfs(void)
{
	queue<int>	q;
	
	d[X] = 0;
	q.push(X);
	
	for(;!q.empty();)
	{
		int	current;
		
		current = q.front();
		q.pop();
		
		vector<int>&	adj = connected[current];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_city = adj[i];
			
			if( d[adj_city] == INF )
			{
				d[adj_city] = d[current]+1;
				q.push(adj_city);
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	bfs();
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( d[i] == K )
		{
			cout<<i<<'\n';
			cnt++;
		}
	}
	
	if( cnt == 0 )
	{
		cout<<"-1\n";
	}
	
	return	0;
}
