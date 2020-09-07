#include	<iostream>

using namespace	std;

int	main(void)
{
	int	n1,n2;
	
	cin>>n1>>n2;
	
	for(;n2!=0;)
	{
		if( n2%n1 == 0 )
		{
			printf("%d is a multiple of %d.\n",n2,n1);
		}
		else
		{
			printf("%d is NOT a multiple of %d.\n",n2,n1);
		}
		cin>>n2;
	}
	return	0;
}
