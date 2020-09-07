#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_FILE	(100000+1)

typedef	unsigned long long	uint64;

int		size[MAX_NUM_OF_FILE];

bool	is_greater(const int& n1,const int& n2)
{
	return	(n1>n2);
}

int		main(void)
{
	int		N;
	uint64	cnt;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&size[i]);
		size[i] *= 10;
	}
	
	sort(&size[1],&size[N+1],is_greater);
	
	cnt = 0;
		
	for(int i=N-1;i>=1;i--)
	{
		for(;N>i&&size[N]<(size[i]/10)*9;N--);
		cnt += N-i;
	}
	printf("%lld\n",cnt);
	
	return	0;
}
