#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,A,B,C,D,X,Y;
	
	cin>>N>>A>>B>>C>>D;
	
	X = N/A+((N%A)?1:0);
	Y = N/C+((N%C)?1:0);
	
	cout<<min(B*X,D*Y)<<'\n';
	
	return	0;
}
