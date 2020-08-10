#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_NUM_OF_NUMBERS	(20+1)

int	main(void)
{
	uint64	S,K,n[MAX_NUM_OF_NUMBERS],M,i;
	
	cin>>S>>K;
	
	for(i=1;i<=K;i++)
	{
		n[i] = S/K;
	}
	
	for(i=1;i<=S%K;i++)
	{
		n[i]++;
	}
	
	for(i=M=1;i<=K;i++)
	{
		M *= n[i];
	}
	
	cout<<M<<endl;
	
	return	0;
}
