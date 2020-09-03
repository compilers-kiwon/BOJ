#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	f,d,n,t;
		
		cin>>f>>d>>n;
		
		if( f==0 && d==0 && n==0 )
		{
			break;
		}
		
		t = (n-f)/d;
		
		if( (t*d)==(n-f) && (t+1)>0 )
		{
			cout<<t+1<<'\n';	
		}
		else
		{
			cout<<"X\n";	
		}	
	}
	
	return	0;
}
