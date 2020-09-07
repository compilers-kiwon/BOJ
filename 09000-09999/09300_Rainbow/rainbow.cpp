#include	<iostream>
#include	<cmath>

using namespace	std;

#define	PI	3.1415926535897

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	for(int n=1;n<=T;n++)
	{
		double	h,t,r,d;
		
		scanf("%lf %lf",&h,&t);
		
		r = t/180.0*PI;
		d = h/tan(r)-h;
		
		printf("Case %d: %.5f\n",n,abs(d));
	}
	
	return	0;
}
