#include	<iostream>

using namespace	std;

#define	MAX_BRIDGE_LEN		(100+1)
#define	MAX_NUM_OF_TRUCK	(1000+1)

int	n,w,L;
int	bridge[MAX_BRIDGE_LEN],current_weight_of_bridge;
int	truck[MAX_NUM_OF_TRUCK];

int	main(void)
{
	cin>>n>>w>>L;
	
	for(int i=1;i<=n;i++)
	{
		cin>>truck[i];
	}
	
	int	time,truck_index;
	
	current_weight_of_bridge = 0;
	truck_index = 1;
	
	for(time=0;truck_index<=n;time++)
	{
		current_weight_of_bridge -= bridge[w];
		bridge[w] = 0;
		
		for(int i=w;i>=2;i--)
		{
			bridge[i] = bridge[i-1];
		}
		
		int	next_weight;
		
		next_weight = current_weight_of_bridge+truck[truck_index];
		
		if( next_weight <= L )
		{
			current_weight_of_bridge += truck[truck_index];
			bridge[1] = truck[truck_index];
			truck_index++;
		}
		else
		{
			bridge[1] = 0;
		}
	}
	
	cout<<time+w<<endl;
	
	return	0;
	
}
