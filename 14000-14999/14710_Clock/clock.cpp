#include	<iostream>

using namespace	std;

int	main(void)
{
	int	h,m;
	
	cin>>h>>m;
	
	if( (h%30)*2*6 == m )
	{
		puts("O");
	}
	else
	{
		puts("X");
	}
	
	return	0;
}
