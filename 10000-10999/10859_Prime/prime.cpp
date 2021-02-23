#include	<iostream>
#include	<cmath>

using namespace	std;

#define	NONE	0

typedef	long long int	int64;

const int64	converted[10] = {0,1,2,-1,-1,5,9,-1,8,6};

int64	reverse_num(int64 n)
{
	int64	ret;
	
	for(ret=0;n>0;n/=10)
	{
		int64	d;
		
		d = converted[n%10];
		
		if( d == -1 )
		{
			return	NONE;
		}
		
		ret = ret*10+d;
	}
	
	return	ret;
}

bool	is_prime(int64 n)
{
	if( n == 1 )
	{
		return	false;
	}
	
	if( n == 2 )
	{
		return	true;
	}
	
	if( n%2 == 0 )
	{
		return	false;
	}
	
	for(int64 i=3,to=sqrt(n);i<=to;i+=2)
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
	int64	N,r;
	
	cin>>N;
	r = reverse_num(N);
	
	if( r == NONE )
	{
		cout<<"no\n";
		return	0;
	}
	
	if( is_prime(N) && is_prime(r) )
	{
		cout<<"yes\n";
	}
	else
	{
		cout<<"no\n";
	}
	
	return	0;
}
