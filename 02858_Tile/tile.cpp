#include	<iostream>

using namespace	std;

int	main(void)
{
	int	R,B,L,W;
	
	cin>>R>>B;
	
	for(L=1;;L++)
	{
		if( 2*((R+B)/L+L-2) == R )
		{
			W = (R+B)/L;
			
			if( L*W == R+B )
			{
				break;
			}
		}
	}
	
	if( L < W )
	{
		swap(L,W);
	}
	cout<<L<<' '<<W<<endl;
	
	return	0;
}
