#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	NONE		0

int	N,graph[MAX_SIZE][MAX_SIZE];

bool	input(void)
{
	cin>>N;
	
	for(int i=1,cnt=0;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>graph[i][j];
			cnt += graph[i][j];
		}
		
		if( cnt%2 == 1 )
		{
			return	false;
		}
	}
	
	return	true;
}

void	dfs(int v)
{
	for(int adj=1;adj<=N;adj++)
	{
		if( graph[v][adj] != NONE )
		{
			--graph[v][adj];--graph[adj][v];
			dfs(adj);
		}
	}
	cout<<v<<' ';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	if( input() == false )
	{
		cout<<"-1\n";
		return	0;
	}
	
	dfs(1);
	
	return	0;
}
