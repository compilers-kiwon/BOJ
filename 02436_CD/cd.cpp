#include	<iostream>
#include	<cmath>

using namespace	std;

int		get_gcd(int a,int b)
{
	int	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod != 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

void	get_others(int n,int& small,int& big,int gcd)
{
	for(int a=sqrt(n);a>=1;a--)
	{
		if( n%a == 0 )
		{
			if( get_gcd(a,n/a) == 1 )
			{
				small = a;
				big = n/a;
				break;
			}
		}
	}
}

int		main(void)
{
	int	gcd,lcm,n,a,b;
	
	cin>>gcd>>lcm;
	
	n = lcm/gcd;
	get_others(n,a,b,gcd);
	
	cout<<a*gcd<<' '<<b*gcd<<'\n';
	
	return	0;	
}
