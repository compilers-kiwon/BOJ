#include	<iostream>

using namespace	std;

#define	MAX_NUM	116

typedef	unsigned long long	uint64;

uint64	get_fibo(int n,uint64* f)
{
	if( f[n] != 0 )
	{
		return	f[n];
	}
	
	f[n] = get_fibo(n-1,f)+get_fibo(n-3,f);
	
	return	f[n];
}

int		main(void)
{
	uint64	fibo[MAX_NUM+1];
	int		n;
	
	fibo[1] = fibo[2] = fibo[3] = 1;
	
	for(int i=4;i<=MAX_NUM;i++)
	{
		fibo[i] = 0;
	}
	
	cin>>n;
	cout<<get_fibo(n,fibo)<<endl;
	
	return	0;
}
