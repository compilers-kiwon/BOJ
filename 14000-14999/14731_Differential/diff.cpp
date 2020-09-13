#include	<iostream>

using namespace	std;

#define	MOD(n)	((n)%1000000007)
#define	INPUT	2

typedef	unsigned long long	uint64;

uint64	pow(uint64 a,uint64 b)
{
	uint64	result;
	
	if( b == 1 )
	{
		result = a;
	}
	else
	{
		if( b%2 == 0 )
		{
			result = MOD(pow(a,b/2)*pow(a,b/2));
		}
		else
		{
			result = MOD(a*pow(a,b-1));
		}
	}
	
	return	result;
}

int		main(void)
{
	int		N;
	uint64	result;
	
	cin>>N;
	result = 0;
	
	for(int i=1;i<=N;i++)
	{
		uint64	C,K,t;

		cin>>C>>K;
		
		if( K == 1 )
		{
			t = C;
		}
		else
		{
			t = MOD(MOD(C*K)*pow(INPUT,K-1));
		}
		
		result = MOD(result+t);
	}
	
	cout<<result<<endl;
	
	return	0;
}
