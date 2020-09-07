#include	<iostream>
#include	<string>

using namespace	std;

typedef	unsigned long long	uint64;

uint64	get_gcd(uint64 a,uint64 b)
{
	uint64	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod > 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

int		main(void)
{
	uint64	A,B,gcd;
	string	n;
	
	cin>>A>>B;
	gcd = get_gcd(A,B);
	
	n.resize(gcd,'1');
	cout<<n<<'\n';
	
	return	0;
}
