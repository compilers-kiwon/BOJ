#include	<iostream>

using namespace	std;

int	main(void)
{
	double	prev;
	
	cin>>prev;
	
	while(1)
	{
		double	current;
		
		cin>>current;
		
		if( current == 999.0 )
		{
			break;
		}
		
		printf("%.02f\n",current-prev);
		prev = current;
	}
	
	return	0;
}
