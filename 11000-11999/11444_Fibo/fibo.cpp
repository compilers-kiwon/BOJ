#include	<iostream>
#include	<map>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MOD	1000000007

map<uint64,uint64>	fibo;

uint64	get_fibo(uint64 index)
{
	uint64	n,f1,f2;
	
	if( index == 0 )
	{
		return	0;
	}
	
	if( index == 1 || index == 2 )
	{
		return	1;
	}
	
	if( fibo[index] != 0 )
	{
		return	fibo[index];
	}
	
	if( index%2 == 1 )
	{
		n = (index+1)/2;
		
		f1 = get_fibo(n);
		f2 = get_fibo(n-1);
		
		fibo[index] = (f1*f1+f2*f2)%MOD;
	}
	else
	{
		n = index/2;
		
		f1 = get_fibo(n);
		f2 = get_fibo(n-1);
		
		fibo[index] = ((f2+f2+f1)*f1)%MOD;
	}
	
	return	fibo[index];
}

int	main(void)
{
	uint64	n;
	
	cin>>n;
	cout<<get_fibo(n)<<endl;
	
	return	0;
}
