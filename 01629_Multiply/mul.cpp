#include	<iostream>
#include	<map>

using namespace	std;

typedef	unsigned long long	uint64;

map<uint64,uint64>	table;

uint64	do_pow(uint64 a,uint64 b,uint64 c)
{
	if( table[b] != 0 )
	{
		return	table[b];
	}
	
	uint64	result;
	
	if( b == 0 )
	{
		table[0] = 1;
		return	1;
	}
	
	if( b%2 == 1 )
	{
		result = (a*do_pow(a,b-1,c))%c;	
	}
	else
	{
		uint64	tmp;
		
		tmp = do_pow(a,b/2,c)%c;
		result = (tmp*tmp)%c;
	}
	table[b] = result;
	
	return	result;
}

int		main(void)
{
	uint64	A,B,C;
	
	cin>>A>>B>>C;
	cout<<do_pow(A,B,C)<<endl;
	
	return	0;
}
