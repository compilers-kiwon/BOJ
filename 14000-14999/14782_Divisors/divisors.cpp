#include	<iostream>
#include	<cmath>

using namespace	std;

int	get_sum_of_divisors(int n)
{
	int	sum,i,to;
	
	for(sum=0,i=1,to=sqrt(n);i<=to;i++)
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
	int	n;
	
	cin>>n;
	cout<<get_sum_of_divisors(n)<<'\n';
	
	return	0;
}
