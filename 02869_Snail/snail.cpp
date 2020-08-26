#include	<iostream>

using namespace	std;

int	main(void)
{
	int	A,B,V,i;
	
	cin>>A>>B>>V;
	
	for(i=1;;i++)
	{
		V -= A;
		
		if( V <= 0 )
		{
			break;
		}
		
		V += B;
	}
	cout<<i<<endl;
	
	return	0;
}
