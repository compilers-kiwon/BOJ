#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CAR				(2000+1)
#define	MAX_SIZE_OF_PARKING_PLACE	(100+1)

int	N,M,total_cost;
int	R[MAX_SIZE_OF_PARKING_PLACE],W[MAX_NUM_OF_CAR];
int	parking_place_of_car[MAX_NUM_OF_CAR];

priority_queue<int>	available;
	
void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>R[i];
		available.push(-i);
	}
	
	for(int i=1;i<=M;i++)
	{
		cin>>W[i];
	}
}

void	simulate(void)
{
	queue<int>			wait_car;
	
	for(int i=1;i<=2*M;i++)
	{
		int	c;
		
		cin>>c;
		
		if( c > 0 )
		{
			if( available.empty() )
			{
				wait_car.push(c);
			}
			else
			{
				parking_place_of_car[c] = -available.top();
				available.pop();
				total_cost += R[parking_place_of_car[c]]*W[c];
			}
		}
		else
		{
			available.push(-parking_place_of_car[-c]);
			
			if( !wait_car.empty() )
			{
				c = wait_car.front();
				wait_car.pop();
				
				parking_place_of_car[c] = -available.top();
				available.pop();
				total_cost += R[parking_place_of_car[c]]*W[c];
			}
		}
	}
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	init();
	simulate();
	
	cout<<total_cost<<'\n';
	
	return	0;
}
