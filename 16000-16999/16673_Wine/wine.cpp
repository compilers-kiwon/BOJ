#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	C,K,P,sum;
	
	cin>>C>>K>>P;
	sum = 0;
	
	for(uint64 n=1;n<=C;n++)
	{
		sum += K*n+P*n*n;
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
