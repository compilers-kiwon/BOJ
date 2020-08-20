#include	<iostream>

using namespace std;

#define	MINUTES_PER_AN_HOUR	60
#define	HOURS_PER_A_DAY		24

int	main(void)
{
	int	A,B,C;
	
	cin>>A>>B>>C;
	
	B = B+C;
	A = A+(B/MINUTES_PER_AN_HOUR);
	
	B = B%MINUTES_PER_AN_HOUR;
	A = A%HOURS_PER_A_DAY;
	
	cout<<A<<' '<<B<<endl;
	
	return	0;
}
