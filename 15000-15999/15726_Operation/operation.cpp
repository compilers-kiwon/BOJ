#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;
typedef	long double			ld64;

int	main(void)
{
	ld64	A,B,C;
	
	cin>>A>>B>>C;
	
	cout<<max((uint64)(A*B/C),(uint64)(A/B*C));
	
	return	0;
}
