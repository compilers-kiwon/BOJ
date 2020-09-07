#include	<iostream>
#include	<cmath>

using namespace	std;

int	get_sum_of_divisors(int n)
{
	int	sum,i,to;
	
	for(sum=1,i=2,to=sqrt(n);i<=to;i++)
	{
		if( n%i == 0 )
		{
			sum += i+(n/i);
		}
	}
	
	if( to*to == n )
	{
		sum -= to;
	}
	
	return	sum;
}

int	main(void)
{
	while(1)
	{
		int	n,s;
		
		scanf("%d",&n);
		
		if( n == 0 )
		{
			break;
		}
		
		s = get_sum_of_divisors(n);
		
		if( s == n )
		{
			printf("%d PERFECT\n",n);
		}
		else if( s > n )
		{
			printf("%d ABUNDANT\n",n);
		}
		else
		{
			printf("%d DEFICIENT\n",n);
		}
	}
	
	return	0;
}
