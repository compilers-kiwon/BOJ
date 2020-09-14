#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,num_of_connected_stations[MAX_SIZE];
	bool	connected[MAX_SIZE][MAX_SIZE];
	
	cin>>N;
	
	for(int to=1;to<=N;to++)
	{
		num_of_connected_stations[to] = 0;
		
		for(int from=1;from<=N;from++)
		{
			connected[from][to] = false;
		}
	}
	
	for(int i=1;i<=N-1;i++)
	{
		int	from,to;
		
		cin>>from>>to;
		
		connected[from][to] = true;
		num_of_connected_stations[to]++;
	}
	
	for(int intermidiate=1;intermidiate<=N;intermidiate++)
	{
		for(int from=1;from<=N;from++)
		{
			for(int to=1;to<=N;to++)
			{
				if( from == to )
				{
					continue;
				}
				
				if( connected[from][to] == false )
				{
					if( connected[from][intermidiate]==true 
						&& connected[intermidiate][to]==true )
					{
						connected[from][to] = true;
						num_of_connected_stations[to]++;
					}
				}
			}
		}
	}
	
	int	station;
	
	station = -1;
	
	for(int i=1;i<=N;i++)
	{
		if( num_of_connected_stations[i] == N-1 )
		{
			station = i;
			break;
		}
	}
	
	cout<<station<<'\n';
	
	return	0;
}
