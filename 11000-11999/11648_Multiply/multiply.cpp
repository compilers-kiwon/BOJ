#include	<iostream>
#include	<string>

using namespace	std;

typedef	unsigned long long	uint64;

int	count_multiply(uint64 n)
{
	if( n < 10 )
	{
		return	0;
	}
	
	uint64	num;
	
	for(num=1;n>0;n/=10)
	{
		num *= (n%10);
	}
	
	return	count_multiply(num)+1;
}

int	main(void)
{
	uint64	n;
	
	cin>>n;
	cout<<count_multiply(n)<<endl;
	
	return	0;
}
