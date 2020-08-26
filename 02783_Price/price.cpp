#include	<iostream>

using namespace	std;

int	main(void)
{
	double	X,Y,min_price;
	int		N;
	
	cin>>X>>Y>>N;
	min_price = 1000*X/Y;
	
	for(int i=1;i<=N;i++)
	{
		double	tmp;
		
		cin>>X>>Y;
		tmp = 1000*X/Y;
		
		min_price = min(min_price,tmp);
	}
	printf("%.02f\n",min_price);
	
	return	0;
}
