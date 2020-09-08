#include	<iostream>

using namespace	std;

int	main(void)
{
	while(1)
	{
		int	a,b,c,d;
		
		cin>>a>>b>>c>>d;
		
		if( a==0 && b==0 && c==0 && d==0 )
		{
			break;
		}
		cout<<c-b<<" "<<d-a<<endl;
	}
	return	0;
}
