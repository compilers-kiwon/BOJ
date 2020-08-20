#include	<iostream>

using namespace	std;

int	main(void)
{
	int	a,b,c;
	int	award;
	
	cin>>a>>b>>c;
	
	if( a==b && b==c )
	{
		award = 10000+a*1000;
	}
	else if( a!=b && b!=c && c!=a )
	{
		award = max(a,max(b,c))*100;
	}
	else
	{
		if( a==b || a==c )
		{
			award = a;
		}
		else
		{
			award = b;
		}
		award = 1000+award*100;
	}
	cout<<award<<endl;
	
	return	0;
}
