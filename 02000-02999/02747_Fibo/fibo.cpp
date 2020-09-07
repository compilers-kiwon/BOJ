#include	<iostream>
#include	<map>

using namespace std;

typedef	unsigned int	uint32;

#define	MAX_N	45

map<uint32,uint32>	cache;

uint32	fibo(uint32 n)
{
	uint32	f;
	
	if( cache[n] != 0xFFFFFFFF )
	{
		return	cache[n];
	}
		
	f = fibo(n-1)+fibo(n-2);
	cache[n] = f;
	return	f;
}

int		main(void)
{
	uint32	n;
	
	cin>>n;
	
	for(uint32 i=0;i<=MAX_N;i++)
	{
		cache[i] = 0xFFFFFFFF;
	}
	cache[0] = 0;
	cache[1] = 1;
	
	cout<<fibo(n)<<endl;
	
	return	0;
}
