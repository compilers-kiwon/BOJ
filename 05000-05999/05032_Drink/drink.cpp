#include	<iostream>

using namespace	std;

int	main(void)
{
	int	e,f,c,n;
	
	cin>>e>>f>>c;
	
	e += f;
	
	for(n=0;e>=c;n++)
	{
		e -= c-1;
	}
	cout<<n<<endl;
	
	return	0;
}
