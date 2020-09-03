#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

uint64	get_gcd(uint64 a,uint64 b)
{
	uint64	small,big;
	
	if( a < b )
	{
		small = a;
		big = b;
	}
	else
	{
		small = b;
		big = a;
	}
	
	if( big%small == 0 )
	{
		return	big;
	}
	
	uint64	gcd = 1;
	
	for(uint64 i=small/2;i>1;i--)
	{
		if( small%i == 0 && big%i == 0 )
		{
			gcd = i;
			break;
		}
	}
	return	gcd;
}

int		main(void)
{
	int	n;
	
	cin>>n;
	
	while(n>0)
	{
		uint64	a,b,gcd,lcm;
		
		cin>>a>>b;
		gcd = get_gcd(a,b);
		lcm = a*b/gcd;
		cout<<lcm<<endl;
		
		n--;
	}
	return	0;
}
