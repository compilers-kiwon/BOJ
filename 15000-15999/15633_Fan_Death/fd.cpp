#include	<iostream>
#include	<cmath>

using namespace	std;

int	get_sum(int n)
{
	int	sum,i,to;
	
	for(sum=0,i=1,to=sqrt(n);i<=to;i++)
	{
		int	tmp;
		
		if( n%i == 0 )
		{
			sum += i+n/i;
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
	cout<<get_sum(n)*5-24<<endl;
	
	return	0;
}
