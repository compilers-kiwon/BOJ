#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	a,b;
		
		cin>>a;
		
		if( a == 0 )
		{
			break;
		}
		
		b = 1;
		
		for(int i=1;i<=a;i++)
		{
			int	s,c;
			
			cin>>s>>c;
			
			b *= s;
			b -= c;
		}
		
		cout<<b<<'\n';
	}
	
	return	0;
}
