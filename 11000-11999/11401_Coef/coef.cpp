#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_NUM	4000000
#define	MOD		1000000007

uint64	factorial[MAX_NUM+1];

uint64	pow(uint64 a,uint64 b)
{
	uint64	result = 1;
	
	if( b == 1 )
	{
		return	a;
	}
	
	result = pow(a,b/2);
	result = (result*result)%MOD;
	
	if( b%2 == 1 )
	{
		result = (result*a)%MOD;
	}
	
	return	result;
}

int		main(void)
{
	uint64	N,K;
	uint64	a,b,c;
	
	cin>>N>>K;
	
	factorial[0] = 1;
	
	for(uint64 i=1;i<=N;i++)
	{
		factorial[i] = (factorial[i-1]*i)%MOD;
	}
	
	a = factorial[N];
	b = factorial[K];
	c = factorial[N-K];
	
	cout<<(((a*pow(b,MOD-2))%MOD)*pow(c,MOD-2))%MOD<<endl;
	
	return	0;
}
