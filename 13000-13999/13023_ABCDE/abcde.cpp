#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	2000
#define	MAX_DEPTH	5

#define	TRUE	1
#define	FALSE	0

int			N,M;
bool		visited[MAX_SIZE];
vector<int>	connected[MAX_SIZE];

int		dfs(int current,int depth)
{
	if( depth == MAX_DEPTH )
	{
		return	TRUE;
	}
	
	vector<int>&	adj = connected[current];
	
	for(int i=0;i<adj.size();i++)
	{
		int&	f = adj[i];
		
		if( visited[f] == false )
		{
			visited[f] = true;
			
			if( dfs(f,depth+1) == TRUE )
			{
				return	TRUE;
			}
			
			visited[f] = false;
		}
	}
	
	return	FALSE;
}

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

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=0;i<N;i++)
	{
		visited[i] = true;
		
		if( dfs(i,1) == TRUE )
		{
			cout<<TRUE<<'\n';
			return	0;
		}
		
		visited[i] = false;
	}
	
	cout<<FALSE<<'\n';
	
	return	0;
}
