#include	<iostream>

using namespace	std;

#define	SUM(n)	((n)*((n)+1)/2)

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	a,b,base,m;
	
	cin>>a>>b;
	base = SUM(a-1);
	m = 1;
	
	for(uint64 i=a;i<=b;i++)
	{
		base += i;
		m *= base;
		m %= 14579;
	}
	
	cout<<m;
	
	return	0;
}
