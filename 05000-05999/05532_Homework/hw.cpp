#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	L,A,B,C,D;
	int	d1,d2;
	
	cin>>L>>A>>B>>C>>D;
	
	d1 = ceil((double)A/(double)C);
	d2 = ceil((double)B/(double)D);
	
	cout<<L-max(d1,d2)<<endl;
	
	return	0;
}
