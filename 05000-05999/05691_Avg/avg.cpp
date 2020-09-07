#include	<iostream>

using namespace	std;

int	main(void)
{
	for(;;)
	{
		int	A,B,C;
		int	big,small;
		
		cin>>A>>B;
		
		if( A == 0 && B == 0 )
		{
			break;
		}
		
		big =max(A,B);
		small = min(A,B);
		C = small-(big-small);
		
		cout<<C<<endl;
	}
	
	return	0;
}
