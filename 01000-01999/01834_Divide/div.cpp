#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	N,sum,r;
	
	cin>>N;
	
	for(sum=0,r=1;r<N;r++)
	{
		sum += r+N*r;
	}
	
	cout<<sum<<endl;
	
	return	0;
}
