#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(10000+1)
#define	INF			(1000000000+1)

typedef	pair<int,int>	Product;	// first:another_sinput,second:output

int				n,m,c[MAX_SIZE];
bool			visited[MAX_SIZE];
vector<Product>	p[MAX_SIZE];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	
	for(int i=1;i<=m;i++)
	{
		int	a,x,y;
		
		cin>>a>>x>>y;
		p[x].push_back(make_pair(y,a));
		p[y].push_back(make_pair(x,a));
	}
}

void	find_min_cost(void)
{
	for(int i=1;i<=n;i++)
	{
		int	cost,idx;
		
		cost = INF;
		
		for(int j=1;j<=n;j++)
		{
			if( visited[j]==false && c[j]<cost )
			{
				cost = c[j];
				idx = j;
			}
		}
		
		visited[idx] = true;
		
		vector<Product>&	current = p[idx];
		
		for(int j=0;j<current.size();j++)
		{
			int&	another_input = current[j].first;
			int&	output = current[j].second;
			int		production_cost;
			
			production_cost = c[another_input]+cost;
			
			if( production_cost < c[output] )
			{
				c[output] = production_cost;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	find_min_cost();

	cout<<c[1]<<'\n';
	
	return	0;
}
