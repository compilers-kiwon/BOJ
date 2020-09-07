#include	<iostream>

using namespace	std;

int	main(void)
{
	int	P;
	
	cin>>P;
	
	while(P>0)
	{
		int		N;
		double	D,A,B,F,t;
	
		cin>>N>>D>>A>>B>>F;
		
		t = D/(A+B);
		printf("%d %.2f\n",N,t*F);
				
		P--;
	}
	return	0;
}
