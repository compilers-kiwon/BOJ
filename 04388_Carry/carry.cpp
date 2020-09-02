#include	<iostream>

using namespace	std;

#define	MAX_DIGIT_LEN	10

typedef	unsigned long long	uint64;

int	count_carry(uint64 a,uint64 b)
{
	int		i,cnt;
	uint64	carry;
	
	for(i=1,cnt=0,carry=0;i<=MAX_DIGIT_LEN;i++)
	{
		uint64	n1,n2,sum;
		
		n1 = a%10;
		n2 = b%10;
		sum = n1+n2+carry;
		
		if( sum >= 10 )
		{
			cnt++;
		}
		carry = sum/10;
		
		a /= 10;
		b /= 10;
	}
	
	return	cnt;
}

int	main(void)
{
	for(;;)
	{
		uint64	a,b;
		
		cin>>a>>b;
		
		if( a == 0 && b == 0 )
		{
			break;
		}
		
		cout<<count_carry(a,b)<<endl;
	}
	
	return	0;
}
