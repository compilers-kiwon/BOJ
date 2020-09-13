#include	<iostream>

using namespace	std;

int	main(void)
{
	int	A,B,C;
	
	cin>>A>>B>>C;
	
	if( A+B >= 2*C )
	{
		cout<<(A+B)-2*C<<endl;
	}
	else
	{
		cout<<A+B<<endl;
	}
	
	return	0;
}
