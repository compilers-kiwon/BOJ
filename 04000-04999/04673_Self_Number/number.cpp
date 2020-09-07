#include	<iostream>
#include	<map>

using namespace	std;

#define	UPPER_BOUND	10000

typedef	unsigned int	uint32;

map<uint32,uint32>	numbers;

uint32	d(uint32 n)
{
	uint32	result,d;
	
	for(result=n,d=n;d>0;d=d/10)
	{
		result = result+d%10;
	}
	return	result;
}

int	main(void)
{
	uint32	i,n;
	
	for(i=1;i<=UPPER_BOUND;i++)
	{
		if( numbers[i] == 0 )
		{
			n = i;cout<<n<<endl;
			
			while( n <= UPPER_BOUND )
			{
				uint32	result;
				
				result = d(n);
				n = result;
				numbers[n]++;
			}
		}
	}
	return	0;
}
