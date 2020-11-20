#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(30000+1)
#define	NONE		0
#define	ROOT		1
#define	ROOT_LEVEL	1

int			n,m;
int			my_parent[MAX_SIZE];
int			my_level[MAX_SIZE];
vector<int>	connected[MAX_SIZE];

void	input(void)
{
	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		
		connected[a].push_back(b);
		connected[b].push_back(a);
	}
}

void	find_parent(void)
{
	queue<int>	q;
	
	q.push(ROOT);
	my_level[ROOT] = ROOT_LEVEL;
	
	for(;!q.empty();)
	{
		int	current;
		
		current = q.front();
		q.pop();
		
		for(int i=0;i<connected[current].size();i++)
		{
			int&	adj = connected[current][i];
			
			if( my_level[adj] != NONE )
			{
				continue;
			}
			
			my_parent[adj] = current;
			my_level[adj] = my_level[current]+1;
			
			q.push(adj);
		}
	}
}

int		get_distance(int from,int to)
{
	int	low,high,ret;
	
	if( my_level[from] < my_level[to] )
	{
		low = from;
		high = to;
	}
	else
	{
		low = to;
		high = from;
	}
	
	for(ret=0;my_level[low]!=my_level[high];ret++)
	{
		high = my_parent[high];
	}
	
	for(;low!=high;ret+=2)
	{
		low = my_parent[low];
		high = my_parent[high];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	find_parent();
	
	int	total_distance;
	
	cin>>m;
	total_distance = 0;
	
	for(int i=1,current=ROOT;i<=m;i++)
	{
		int	dest;
		
		cin>>dest;
		total_distance += get_distance(current,dest);
		
		current = dest;
	}
	
	cout<<total_distance<<'\n';
	
	return	0;
}
