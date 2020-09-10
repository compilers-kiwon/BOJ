#include	<iostream>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

int	main(void)
{
	int	N;
	
	cin>>N;
	
	while( N>0 )
	{
		int	lsb;
		
		lsb = N & 0x1;
		N = N>>1;
		if( lsb == 1 )
		{
			break;
		}
	}
	
	if( N == 0 )
	{
		cout<<TRUE<<endl;
	}
	else
	{
		cout<<FALSE<<endl;
	}
	
	return	0;
}
