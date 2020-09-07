#include	<iostream>

using namespace	std;

int	main(void)
{
	int	C,K,n,i,a,b;
	
	cin>>C>>K;
	
	for(n=1,i=1;i<=K;i++)
	{
		n *= 10;
	}
	
	a = C/n;
	b = C%n;
	
	if( b >= n/2 )
	{
		a++;
	}
	cout<<a*n<<endl;
	
	return	0;
}
