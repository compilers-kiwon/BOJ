#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	count[MAX_SIZE+1];
	
	count[1] = 1;
	
	for(uint64 i=2;i<=MAX_SIZE;i++)
	{
		count[i] = count[i-1]+i*i; 
	}
	
	while(1)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		cout<<count[N]<<endl;
	}
	return	0;
}
