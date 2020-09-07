#include	<iostream>

using namespace	std;

int	main(void)
{
	while(1)
	{
		int	a,b;
		
		cin>>a>>b;
		
		if( a==0 && b==0 )
		{
			break;
		}
		
		cout<<((a>b)?"Yes":"No")<<endl;
	}
	return	0;
}
