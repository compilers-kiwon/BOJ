#include	<iostream>

using namespace	std;

#define	PI	3.141592

int	main(void)
{
	double	d1,d2,R;
	
	cin>>d1>>d2;
	R = d2+d2;
	
	printf("%.6f\n",d1+d1+R*PI);
	
	return	0;
}
