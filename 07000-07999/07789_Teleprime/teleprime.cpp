#include	<iostream>
#include	<cmath>

using namespace	std;

#define	FIRST_DIGIT_NUM	1000000

bool	is_prime(int n)
{
	for(int i=2,to=sqrt(n);i<=to;i++)
	{
		if( n%i == 0 )
		{
			return	false;
		}
	}
	
	return	true;
}

int		main(void)
{
	int	n1,n2;
	
	cin>>n1>>n2;
	n2 = n2*FIRST_DIGIT_NUM+n1;
	
	if( is_prime(n1) && is_prime(n2) )
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	
	return	0;
}
