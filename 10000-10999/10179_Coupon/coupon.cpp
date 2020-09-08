#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		double	p;
		
		scanf("%lf",&p);
		printf("$%.2f\n",p*0.8);
		
		T--;
	}
	
	return	0;
}
