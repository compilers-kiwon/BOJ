#include	<iostream>

using namespace	std;

int	main(void)
{
	int	A,B,C;
	
	cin >>A>>B>>C;
	
	if( C%2 == 1 )
	{
		cout<<(A^B)<<endl;
	}
	else
	{
		cout<<A<<endl;
	}
	return	0;
}
