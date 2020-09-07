#include	<iostream>
#include	<cmath>

using namespace	std;

#define	NUM_OF_MUSHROOMS	10

int	main(void)
{
	int	mushroom[NUM_OF_MUSHROOMS];
	int	sum;
	
	for(int i=0;i<NUM_OF_MUSHROOMS;i++)
	{
		cin>>mushroom[i];
	}
	
	sum = 0;
	
	for(int i=0;i<NUM_OF_MUSHROOMS;i++)
	{
		if( abs(sum+mushroom[i]-100) <= abs(sum-100) )
		{
			sum += mushroom[i];
		}
		else
		{
			break;
		}
	}
	cout<<sum<<endl;
	
	return	0;
}
