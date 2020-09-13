#include	<iostream>

using namespace	std;

int	main(void)
{
	int	a,b,m,x;
	
	cin>>a>>m;
	
	for(x=1,b=a;b%m!=1;b+=a,x++);
	
	cout<<x<<endl;
	
	return	0;
}
