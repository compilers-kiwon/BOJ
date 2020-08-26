#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		double	n;
		string	u;
			
		cin>>n>>u;
		
		if( u == "kg" )
		{
			printf("%.4f lb\n",n*2.2046);
		}
		else if( u == "lb" )
		{
			printf("%.4f kg\n",n*0.4536);
		}
		else if( u == "l" )
		{
			printf("%.4f g\n",n*0.2642);
		}
		else
		{
			printf("%.4f l\n",n*3.7854);
		}
		T--;
	}
	
	return	0;
}
