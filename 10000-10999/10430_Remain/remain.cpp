#include	<iostream>

using namespace	std;

int	main(void)
{
	int	A,B,C;
	
	cin>>A>>B>>C;
	cout<<(A+B)%C<<endl<<(A%C+B%C)%C<<endl<<(A*B)%C<<endl<<(A%C*B%C)%C<<endl;
	
	return	0;
}
