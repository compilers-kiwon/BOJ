#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CITY	(1000+1)
#define	MAX_COST		(100000+1)

typedef	pair<int,int>	Path;	// first:to, second:cost
typedef	pair<int,int>	State;	// first:-cost, second:from

int	n,m,A,B,dp[MAX_NUM_OF_CITY],where_is_from[MAX_NUM_OF_CITY];

vector<Path>	connected[MAX_NUM_OF_CITY];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	a,b,c;
		
		cin>>a>>b>>c;
		connected[a].push_back(make_pair(b,c));
	}
	
	cin>>A>>B;
	
	for(int i=1;i<=n;i++)
	{
		dp[i] = 0x7FFFFFFF;
		where_is_from[i] = -1;
	}
	dp[A] = 0;
}

void	find_min_path(void)
{
	priority_queue<State>	pq;	
	
	pq.push(make_pair(0,A));
	
	while( !pq.empty() )
	{
		int	current_city,current_cost;
		
		current_cost = -pq.top().first;
		current_city = pq.top().second;
		
		pq.pop();
		
		if( current_city == B )
		{
			break;
		}
		
		if( current_cost > dp[current_city] )
		{
			continue;
		}
		
		for(int i=0;i<connected[current_city].size();i++)
		{
			int	adj_city,adj_cost;
			
			adj_city = connected[current_city][i].first;
			adj_cost = connected[current_city][i].second+current_cost;
			
			if( adj_cost < dp[adj_city] )
			{
				dp[adj_city] = adj_cost;
				pq.push(make_pair(-adj_cost,adj_city));
				where_is_from[adj_city] = current_city;
			}
		}
	}
}

int		main(void)
{
	input();
	find_min_path();
	
	vector<int>	p;
	
	for(int i=B;i!=-1;i=where_is_from[i])
	{
		p.push_back(i);
	}
    
	cout<<dp[B]<<endl<<p.size()<<endl;
	
	for(int i=p.size()-1;i>=0;i--)
	{
		cout<<p[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
