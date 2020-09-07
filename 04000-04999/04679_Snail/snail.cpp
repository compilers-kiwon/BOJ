#include	<iostream>

using namespace	std;

bool	climb(int H,int U,int D,int F,int& day)
{
	int		initial_height,disctance_climbed,hegiht_after_climbing;
	int		sliding_distance,height_after_sliding;
	int		final,decrement;
	bool	result;
	
	initial_height = 0;
	disctance_climbed = U*100;
	sliding_distance = D*100;
	final = H*100;
	decrement = U*F;
	
	for(day=1;;day++)
	{
		hegiht_after_climbing = initial_height+max(0,disctance_climbed);
		
		if( hegiht_after_climbing > final )
		{
			result = true;
			break;
		}
		
		height_after_sliding = hegiht_after_climbing-sliding_distance;
		
		if( height_after_sliding < 0 )
		{
			result = false;
			break;
		}
		
		disctance_climbed -= decrement;
		initial_height = height_after_sliding;
	}
	
	return	result;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	while(1)
	{
		int	H,U,D,F,d;
		
		cin>>H>>U>>D>>F;
		
		if( H == 0 )
		{
			break;
		}
		
		if( climb(H,U,D,F,d) == true )
		{
			cout<<"success on day "<<d<<'\n';
		}
		else
		{
			cout<<"failure on day "<<d<<'\n';
		}
	}
	
	return	0;
}
