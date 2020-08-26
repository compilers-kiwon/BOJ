#include	<iostream>

using namespace	std;

#define	MAX_NUM	(90+1)

typedef	unsigned long long	uint64;

uint64	fibo[MAX_NUM];

int	main(void)
{
	int	n;
	
	cin>>n;
	
	fibo[0] = 0;
	fibo[1] = 1;
	
	for(int i=2;i<=n;i++)
	{
		fibo[i] = fibo[i-1]+fibo[i-2];
	}
	cout<<fibo[n]<<endl;
	
	return	0;
}
