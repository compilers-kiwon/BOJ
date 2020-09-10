#include	<iostream>
#include	<map>

using namespace std;

typedef	unsigned long long	uint64;

map<uint64,uint64>	cache;

uint64	f(uint64 n)
{
	if( cache[n] != 0 )
	{
		return	cache[n];
	}
	
	uint64	v;
	
	v = (f(n-1)+f(n-2))%10007;
	cache[n] = v;
	return	v;
}

int		main(void)
{
	uint64	n;
	
	cache[1] = 1;
	cache[2] = 2;
	
	cin>>n;
	cout<<f(n)%10007<<endl;
	
	return	0;
}
