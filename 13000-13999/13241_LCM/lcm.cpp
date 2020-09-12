#include	<iostream>

using namespace	std;

typedef	long long int	int64;

int	get_gcd(int a,int b)
{
	int	gcd,i,small,big;
	
	small = min(a,b);
	big = max(a,b);
	
	if( big%small == 0 )
	{
		gcd = small;
	}
	else
	{
		gcd = 1;
		
		for(i=small/2;i>=2;i--)
		{
			if( a%i == 0 && b%i == 0 )
			{
				gcd = i;
				break;
			}
		}
	}
	
	return	gcd;
}

int	main(void)
{
	int		A,B,gcd;
	int64	lcm;
	
	cin>>A>>B;
	
	gcd = get_gcd(A,B);
	lcm = (int64)A*(int64)B/(int64)gcd;
	
	cout<<lcm<<endl;
	
	return	0;
}
