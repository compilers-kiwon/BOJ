#include	<iostream>

using namespace	std;

#define	NUM_OF_TILES	80

typedef	unsigned long long	uint64;

uint64	tile[NUM_OF_TILES+1];

int		main(void)
{
	int		N;
	uint64	len;
	
	tile[1] = tile[2] = 1;
	
	for(int i=3;i<=NUM_OF_TILES;i++)
	{
		tile[i] = tile[i-1]+tile[i-2];
	}
	
	cin>>N;
	
	if( N < 4 )
	{
		if( N == 3 )
		{
			len = 10;
		}
		else if( N == 2 )
		{
			len = 6;
		}
		else
		{
			len = 4;
		}
	}
	else
	{
		len = tile[N]*3+tile[N-1]*2+tile[N-2]*2+tile[N-3]*1;
	}
	
	cout<<len<<endl;
	
	return	0;
}
