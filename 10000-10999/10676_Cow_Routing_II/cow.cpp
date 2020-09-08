#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_ROUTE	(500+1)
#define	MAX_NUM_OF_CITY		(10000+1)

int			A,B,N,route_cost[MAX_NUM_OF_ROUTE];
vector<int>	route_info[MAX_NUM_OF_ROUTE];
vector<int>	connected_route[MAX_NUM_OF_CITY];

bool	is_reachable(int route,int from,int to)
{
	int	from_index,to_index;
	
	from_index = to_index = -1;
	
	for(int i=0;i<route_info[route].size();i++)
	{
		if( route_info[route][i] == from )
		{
			from_index = i;
		}
		else if( route_info[route][i] == to )
		{
			to_index = i;
		}
	}
	
	return	(from_index<to_index);
}

void	init(void)
{
	cin>>A>>B>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>route_cost[i]>>n;
		
		for(int j=1;j<=n;j++)
		{
			int	c;
			
			cin>>c;
			
			route_info[i].push_back(c);
			connected_route[c].push_back(i);
		}
	}
}

int		get_min_cost(void)
{
	int	result;
	
	result = 0x7FFFFFFF;
	
	vector<int>&	from_route = connected_route[A];
	
	for(int i=0;i<from_route.size();i++)
	{
		int&	current_route = from_route[i];
		
		if( is_reachable(current_route,A,B) == true )
		{
			result = min(result,route_cost[current_route]);
		}
		else
		{
			bool	flag;
			
			flag = false;
			
			for(int j=0;j<route_info[current_route].size();j++)
			{
				int&	adj_city = route_info[current_route][j];
				
				if( adj_city == A )
				{
					flag = true;
					continue;
				}
				
				if( flag == true )
				{
					vector<int>&	second_route = connected_route[adj_city];
					
					for(int k=0;k<second_route.size();k++)
					{
						if( is_reachable(second_route[k],adj_city,B) == true )
						{
							result = min(result,route_cost[current_route]+route_cost[second_route[k]]);
						}
					}
				}
			}
		}
	}
	
	if( result == 0x7FFFFFFF )
	{
		result = -1;
	}
	
	return	result;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	cout<<get_min_cost()<<'\n';
	
	return	0;
}
