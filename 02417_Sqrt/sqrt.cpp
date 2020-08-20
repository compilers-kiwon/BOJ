#include	<iostream>
#include	<cmath>

using namespace	std;

typedef	long long int	int64;

int	main(void)
{
	int64	n,q;
	
	cin>>n;
	q = sqrt(n);
	
	if( q*q < n )
	{
		q++;
	}
	
	cout<<q<<'\n';
	
	return	0;
}
