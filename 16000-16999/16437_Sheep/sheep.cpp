#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_ISLAND	(123456+1)

#define	WOLF	'W'
#define	SHEEP	'S'

typedef	long long int	int64;

int			N;
vector<int>	connected[MAX_NUM_OF_ISLAND];
bool		visited[MAX_NUM_OF_ISLAND];
int64		island_info[MAX_NUM_OF_ISLAND];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=2;i<=N;i++)
	{
		char	t;
		int64&	a = island_info[i];
		int		p;
		
		cin>>t>>a>>p;
		
		if( t == WOLF )
		{
			a = -a;
		}
		
		connected[p].push_back(i);
		connected[i].push_back(p);
	}
}

int64	dfs(int island)
{
	visited[island] = true;
	
	int64&	ret = island_info[island];
	
	for(int i=0;i<connected[island].size();i++)
	{
		int&	adj_island = connected[island][i];
		
		if( visited[adj_island] == false )
		{
			ret += max((int64)0,dfs(adj_island));
		}
	}
	
	return	ret;
}

int		main(void)
{
	init();
	cout<<dfs(1)<<'\n';
	
	return	0;
}
