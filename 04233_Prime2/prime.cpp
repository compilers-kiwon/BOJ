#include	<iostream>
#include	<cmath>

using namespace	std;

typedef	long long int	int64;

#define	MOD(A,B)	((A)%(B))

int64	get_pow(int64 a,int64 p,int64 m)
{
	if( p == 1 )
	{
		return	a;
	}
	
	int64	result;
	
	result = MOD(get_pow(a,p/2,m),m);
	result = MOD(result*result,m);
	
	if( p%2 == 1 )
	{
		result = MOD(result*a,m);
	}
	
	return	result;
}

bool	is_prime(int n)
{
	bool	flag;
	int		i,to;
	
	for(flag=true,i=2,to=sqrt(n);i<=to;i++)
	{
		if( n%i == 0 )
		{
			flag = false;
			break;
		}
	}
	
	return	flag;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	while(1)
	{
		int64	p,a;
		
		cin>>p>>a;
		
		if( p==0 && a==0 )
		{
			break;
		}
		
		if( get_pow(a,p,p)==a && is_prime((int)p)==false )
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	
	return	0;
}
