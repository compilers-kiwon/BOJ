#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(10000000+1)

typedef	unsigned long long	uint64;

int		N;
uint64	number[MAX_SIZE];

int	main(void)
{
	cin>>N;
	
	number[1] = 5;
	
	for(int i=2;i<=N;i++)
	{
		number[i] = (number[i-1]+(i-1)*3+4)%45678;
	}
	
	cout<<number[N];
	
	return	0;
}
