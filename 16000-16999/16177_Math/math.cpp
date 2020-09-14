#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	A,B,C,D;
	
	for(;scanf("%d %d %d %d",&A,&B,&C,&D)==4;)
	{
		int		x,y,z;
		bool	found;
		
		found = false;
		
		for(x=0;x<(1<<16);x++)
		{
			z = A-x*x-x*x*x*x+2*x*x*D-D*D;
			
			if( z<0 || z>(1<<16) )
			{
				continue;
			}
			
			y = x*x-D;
			
			if( y<0 || y>(1<<16) )
			{
				continue;
			}
			
			if( pow(x+y,B)+y == C )
			{
				found = true;
				break;
			}
		}
		
		if( found == true )
		{
			printf("%d %d %d\n",x,y,z);
		}
		else
		{
			puts("No solution");
		}
	}
	
	return	0;
}
