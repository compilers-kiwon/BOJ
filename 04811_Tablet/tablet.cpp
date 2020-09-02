#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

#define	NUM_OF_DAYS	30

int	main(void)
{
	uint64	table[NUM_OF_DAYS+1][NUM_OF_DAYS+1];
	
	for(int i=0;i<=NUM_OF_DAYS;i++)
	{
		for(int j=0;j<=NUM_OF_DAYS;j++)
		{
			table[i][j] = 0;
		}
	}
	
	for(int i=1;i<=NUM_OF_DAYS;i++)
	{
		table[0][i] = 1;
	}
	
	for(int i=1;i<=NUM_OF_DAYS;i++)
	{
		for(int j=i;j<=NUM_OF_DAYS;j++)
		{
			table[i][j] = table[i-1][j]+table[i][j-1];
		}
	}
	
	while(1)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		cout<<table[N][N]<<endl;
	}
	
	return	0;
}
