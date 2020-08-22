#include	<iostream>

using namespace	std;

typedef	unsigned int	uint32;

uint32	get_gcd(uint32 a,uint32 b)
{
	uint32	i,to,gcd;
	
	to = min(a,b);
	
	for(gcd=1,i=to;i>=2;i--)
	{
		if( a%i == 0 && b%i == 0 )
		{
			gcd = i;
			break;
		}
	}
	return	gcd;
}

uint32	get_lcm(uint32 gcd,uint32 a,uint32 b)
{
	uint32	c,d;
	
	c = a/gcd;
	d = b/gcd;
	
	return	gcd*c*d;
}

int		main(void)
{
	uint32	a,b,gcd,lcm;
	
	cin>>a>>b;
	
	gcd = get_gcd(a,b);
	lcm = get_lcm(gcd,a,b);
	
	cout<<gcd<<endl<<lcm<<endl;
	
	return	0;
}
