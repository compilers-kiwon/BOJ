#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	double	A,B,C,N;
	
	cin>>A>>B>>C;
	
	N = sqrt((A*A)/(B*B+C*C));
	cout<<(int)(N*B)<<' '<<(int)(N*C)<<'\n';
	
	return	0;
}
