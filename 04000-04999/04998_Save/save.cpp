#include	<iostream>

using namespace	std;

int	main(void)
{
	double	N,B,M;
	
	while( scanf("%lf %lf %lf",&N,&B,&M) != EOF )
	{
		int	year;
		
		for(year=0;N<M;year++)
		{
			N += N*(B/100.0);
		}
		cout<<year<<endl;
	}
	return	0;
}
