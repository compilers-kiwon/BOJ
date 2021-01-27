#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int			n,m,q,visit_cnt;
int			visited[MAX_SIZE];
vector<int>	connected[MAX_SIZE];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	u,v;
		
		cin>>u>>v;
		
		connected[u].push_back(v);
		connected[v].push_back(u);
	}
	
	cin>>q;
}

void	build_path(void)
{
	int	i,j;
	
	cin>>i>>j;
	
	connected[i].push_back(j);
	connected[j].push_back(i);
}

void	print(int* dp)
{
	for(int i=1;i<=n;i++)
	{
		if( visited[i] != visit_cnt )
		{
			cout<<"-1 ";
		}
		else
		{
			cout<<dp[i]<<' ';
		}
	}
	
	cout<<'\n';
}

void	bfs(int* dp)
{
	queue<int>	visited_city;
	
	visited_city.push(1);
	visited[1] = visit_cnt;
	
	for(dp[1]=0;!visited_city.empty();)
	{
		int	current_city;
		
		current_city = visited_city.front();
		visited_city.pop();
		
		for(int i=0;i<connected[current_city].size();i++)
		{
			int&	adj_city = connected[current_city][i];
			
			if( visited[adj_city] != visit_cnt )
			{
				visited_city.push(adj_city);
				visited[adj_city] = visit_cnt;
				dp[adj_city] = dp[current_city]+1;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=1;i<=q;i++)
	{
		int	dp[MAX_SIZE];
		
		build_path();
		visit_cnt++;
		
		bfs(dp);
		print(dp);
	}
	
	return	0;
}
