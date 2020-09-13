#include	<iostream>
#include	<cfloat>

using namespace	std;

int	main(void)
{
	double	K,P,X,min_cost,prev;
	
	cin>>K>>P>>X;
	prev = DBL_MAX;
	
	for(double M=1.0;;M+=1.0)
	{
		double	current;
		
		current = M*X+(K/M)*P;
		
		if( current >= prev )
		{
			min_cost = prev;
			break;
		}
		
		prev = current;
	}
	
	printf("%.03f\n",min_cost);
	
	return	0;
}
