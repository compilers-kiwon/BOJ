#include	<iostream>

using namespace	std;

int	main(void)
{
	int		N;
	double	A,B;
	
	scanf("%lf %lf %d",&A,&B,&N);
	
	for(int i=1;i<=N;i++)
	{
		double	n,t;
		char	c;
		
		scanf("%lf %c",&n,&c);
		
		if( c == 'A' )
		{
			t = B*n/A;
		}
		else
		{
			t = A*n/B;
		}
		
		printf("%.04f\n",t);
	}
	
	return	0;
}
