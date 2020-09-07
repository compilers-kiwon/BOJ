#include	<iostream>

using namespace	std;

int	main(void)
{
	for(int i=1;;i++)
	{
		int	r,w,l;
		
		cin>>r;
		
		if( r == 0 )
		{
			break;
		}
		
		cin>>w>>l;
		
		if( 4*r*r >= l*l+w*w )
		{
			printf("Pizza %d fits on the table.\n",i);
		}
		else
		{
			printf("Pizza %d does not fit on the table.\n",i);
		}
	}
	return	0;
}
