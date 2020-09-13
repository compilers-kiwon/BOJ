#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_NUM	10000

int	get_sum_of_div(int n)
{
	int	i,to,sum;
	
	for(i=2,sum=1,to=sqrt(n);i<=to;i++)
	{
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
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int	N,s;
		
		cin>>N;
		
		if( N == 1 )
		{
			s = 0;
		}
		else
		{
			s = get_sum_of_div(N);
		}
		
		if( s > N )
		{
			cout<<"Abundant\n";
		}
		else if( s < N )
		{
			cout<<"Deficient\n";
		}
		else
		{
			cout<<"Perfect\n";
		}
	}
	
	return	0;
}
