#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_CITY	(100+1)

#define	CONNECTED		'1'
#define	NOT_CONNECTED	'0'

char	map[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY+1];
int		N,police_cost[MAX_NUM_OF_CITY];
bool	visited[MAX_NUM_OF_CITY];

int		main(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>police_cost[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&map[i][1]);
		map[i][i] = CONNECTED;
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( map[i][j] == NOT_CONNECTED && map[i][k] == CONNECTED && map[k][j] == CONNECTED )
				{
					map[i][j] = CONNECTED;
				}
			}
		}
	}
	
	int	total_cost;
	
	total_cost = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( visited[i] == true )
		{
			continue;
		}
		
		int	min_cost,min_cost_city;
		
		min_cost = 0x7FFFFFFF;
		
		for(int j=1;j<=N;j++)
		{
			if( map[j][i] == CONNECTED && map[i][j] == CONNECTED )
			{
				if( police_cost[j] < min_cost )
				{
					min_cost = police_cost[j];
					min_cost_city = j;
				}
			}
		}
		
		for(int j=1;j<=N;j++)
		{
			if( map[min_cost_city][j] == CONNECTED && map[j][min_cost_city] == CONNECTED )
			{
				visited[j] = true;
			}
		}
		
		total_cost += min_cost;
	}
	
	cout<<total_cost<<'\n';
	
	return	0;
}
