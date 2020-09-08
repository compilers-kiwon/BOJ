#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(50000+1)
#define	NONE		0

int			N,M;
int			parent[MAX_SIZE],depth[MAX_SIZE];
bool		visited[MAX_SIZE];
vector<int>	connected[MAX_SIZE];

void	bfs(int n)
{
	for(int i=0;i<connected[n].size();i++)
	{
		int&	adj_node = connected[n][i];
		
		if( visited[adj_node] == false )
		{
			parent[adj_node] = n;
			depth[adj_node] = depth[n]+1;
			
			visited[adj_node] = true;			
			bfs(adj_node);
		}
	}
}

void	build_tree(void)
{
	cin>>N;
	
	for(int i=1;i<=N-1;i++)
	{
		int	n1,n2;
		
		cin>>n1>>n2;
		
		connected[n1].push_back(n2);
		connected[n2].push_back(n1);
	}
	
	visited[1] = true;
	bfs(1);
}

int		find_parent(int higher_node,int lower_node)
{
	for(;depth[lower_node]!=depth[higher_node];lower_node=parent[lower_node]);
	
	for(;higher_node!=lower_node;)
	{
		higher_node = parent[higher_node];
		lower_node = parent[lower_node];
	}
	
	return	higher_node;
}

void	do_query(void)
{
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	n1,n2,higher,lower;
		
		cin>>n1>>n2;
		
		if( depth[n1] < depth[n2] )
		{
			higher = n1;
			lower = n2;
		}
		else
		{
			higher = n2;
			lower = n1;
		}
		
		cout<<find_parent(higher,lower)<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	build_tree();
	do_query();
	
	return	0;
}
