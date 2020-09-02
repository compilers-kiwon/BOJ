#include	<iostream>

using namespace	std;

int	main(void)
{
	for(;;)
	{
		double	w;
		
		scanf("%lf",&w);
		
		if( w < 0.0)
		{
			break;
		}
		
		printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n",w,w*0.167);
	}
	
	return	0;
}
