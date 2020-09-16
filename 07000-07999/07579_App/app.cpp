#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_COST	(10000+1)

int	N,M,free_memory_table[MAX_SIZE][MAX_COST];
int	m[MAX_SIZE],c[MAX_SIZE];

int	main(void)
{
	cin>>N>>M;
	
	for(int app=0;app<=N;app++)
	{
		fill(&free_memory_table[app][0],&free_memory_table[app][MAX_COST],-1);
	}
	
	free_memory_table[0][0] = 0;
	
	for(int app=1;app<=N;app++)
	{
		cin>>m[app];
	}
	
	for(int app=1;app<=N;app++)
	{
		cin>>c[app];
	}
	
	for(int app=1;app<=N;app++)
	{
		int&	current_app_memory = m[app];
		int&	current_app_cost = c[app];
		int		prev_app;
		
		prev_app = app-1;
		
		for(int cost=0;cost<MAX_COST;cost++)
		{
			if( free_memory_table[prev_app][cost] != -1 )
			{
				free_memory_table[app][cost] =
					max(free_memory_table[prev_app][cost],free_memory_table[app][cost]);
				
				free_memory_table[app][cost+current_app_cost] =
					max(free_memory_table[app][cost+current_app_cost],
						free_memory_table[prev_app][cost]+current_app_memory);
			}
		}
	}
	
	int		min_cost;
	int&	last_app = N;
	
	min_cost = MAX_COST;
		
	for(int cost=0;cost<MAX_COST;cost++)
	{
		if( free_memory_table[last_app][cost] >= M )
		{
			min_cost = min(min_cost,cost);
		}
	}
	
	cout<<min_cost<<'\n';
	
	return	0;
}
