#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	for(int i=1;;i++)
	{
		double	a,b,c,answer;
		char	x;
		
		cin>>a>>b>>c;
		
		if( a == 0.0 && b == 0.0 && c == 0.0 )
		{
			break;
		}
		
		if( a < 0.0 )
		{
			answer = c*c-b*b;
			x = 'a';
		}
		else if( b < 0.0 )
		{
			answer = c*c-a*a;
			x = 'b';
		}
		else
		{
			answer = a*a+b*b;
			x = 'c';
		}
		
		printf("Triangle #%d\n",i);
		
		if( answer > 0 )
		{
			printf("%c = %.3f\n\n",x,sqrt(answer));
		}
		else
		{
			puts("Impossible.\n");
		}
	}
	
	return	0;
}
