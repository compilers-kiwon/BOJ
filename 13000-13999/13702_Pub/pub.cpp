#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_KETTLE	(10000+1)

typedef	unsigned long long	uint64;

int		N;
uint64	K,kettle[MAX_NUM_OF_KETTLE];

void	input(uint64& max_kettle)
{
	cin>>N>>K;
	
	max_kettle = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>kettle[i];
		max_kettle = max(max_kettle,kettle[i]);
	}
}

uint64	get_cnt(uint64 n)
{
	uint64	cnt;
	int		i;
	
	for(i=1,cnt=0;i<=N;i++)
	{
		cnt += kettle[i]/n;
	}
	
	return	cnt;
}

uint64	bin_search(uint64 lo,uint64 hi)
{
	uint64	mid,cnt;
	
	while(lo+1<hi)
	{
		mid = (lo+hi)/2;
		cnt = get_cnt(mid);
		
		if( cnt >= (uint64)K )
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	
	return	lo;
}

int		main(void)
{
	uint64	max_kettle;
	
	input(max_kettle);
	cout<<bin_search(1,max_kettle+1)<<'\n';
	
	return	0;
}