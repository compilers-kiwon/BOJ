#include	<iostream>

using namespace	std;

#define	BR	350.34
#define	SS	230.90
#define	HS	190.55
#define	ARM	125.30
#define	LEG	180.90

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		double	a,b,c,d,e;
		
		cin>>a>>b>>c>>d>>e;
		printf("$%.02f\n",BR*a+SS*b+HS*c+ARM*d+LEG*e);
		
		T--;
	}
	return	0;
}
