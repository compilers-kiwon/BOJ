#include	<iostream>

using namespace	std;

int	main(void)
{
	int	t,m;
	
	cin>>t>>m;
	
	if( m >=45 )
	{
		m = m-45;
	}
	else
	{
		if( t == 0 )
		{
			t = 23;
		}
		else
		{
			t--;
		}
		m = m+15;		
	}
	
	cout<<t<<' '<<m<<endl;
	
	return	0;
}
