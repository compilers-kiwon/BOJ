#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	r,e,c;
		
		cin>>r>>e>>c;
		
		if( r > e-c )
		{
			cout<<"do not advertise\n";
		}
		else if( r == e-c )
		{
			cout<<"does not matter\n";
		}
		else
		{
			cout<<"advertise\n";
		}
	}
	return	0;
}
