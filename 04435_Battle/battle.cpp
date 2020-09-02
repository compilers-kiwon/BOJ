#include	<iostream>

using namespace	std;

#define	KINDS_OF_G_SOLDIER	6
#define	KINDS_OF_S_SOLDIER	7

typedef	unsigned int	uint32;

int	main(void)
{
	uint32	g_soldier_ability[KINDS_OF_G_SOLDIER] = {1,2,3,3,4,10};
	uint32	s_soldier_ability[KINDS_OF_S_SOLDIER] = {1,2,2,2,3,5,10};
	uint32	T;
	
	cin>>T;
	
	for(uint32 i=1;i<=T;i++)
	{
		uint32	sum_of_g,sum_of_s;
		
		sum_of_g = sum_of_s = 0;
		
		for(int j=0;j<KINDS_OF_G_SOLDIER;j++)
		{
			uint32	n;
			
			cin>>n;
			sum_of_g += n*g_soldier_ability[j];
		}
		
		for(int j=0;j<KINDS_OF_S_SOLDIER;j++)
		{
			uint32	n;
			
			cin>>n;
			sum_of_s += n*s_soldier_ability[j];
		}
		
		cout<<"Battle "<<i<<": ";
		
		if( sum_of_g > sum_of_s )
		{
			cout<<"Good triumphs over Evil\n";
		}
		else if( sum_of_g < sum_of_s )
		{
			cout<<"Evil eradicates all trace of Good\n";
		}
		else
		{
			cout<<"No victor on this battle field\n";
		}
	}
	
	return	0;
}
