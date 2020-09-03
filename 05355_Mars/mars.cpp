#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		double	d;
		char	c;
		
		cin>>d;
		
		while( (c=getchar()) != '\n' )
		{
			if( c == '@' )
			{
				d *= 3.0;
			}
			else if( c == '%' )
			{
				d += 5.0;
			}
			else if( c == '#' )
			{
				d -= 7.0;
			}
		 }
		 printf("%.02f\n",d);
		  
		T--;
	}
	return	0;
}
