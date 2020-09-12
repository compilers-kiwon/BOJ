#include	<iostream>

using namespace	std;

#define	MAX_SIZE	64
#define	MOD(n)		((n)%1000000007)

typedef	unsigned long long	uint64;

uint64	pow_value[MAX_SIZE+1];

void	init(uint64& A,uint64& X)
{
	cin>>A>>X;
	
	pow_value[1] = MOD(A);
	
	for(int i=2;i<=MAX_SIZE;i++)
	{
		pow_value[i] = MOD(pow_value[i-1]*pow_value[i-1]);
	}
}

uint64	get_value(uint64 exp)
{
	uint64	result;
	int		index;
	
	result = index = 1;
	
	while(exp>0)
	{
		if( exp%2 == 1 )
		{
			result = MOD(result*pow_value[index]);
		}
		exp /= 2;
		index++;
	}
	
	return	result;
}

int		main(void)
{
	uint64	A,X;
	
	init(A,X);
	cout<<get_value(X)<<endl;
	
	return	0;	
}
