#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_KETTLE	(10000+1)

typedef	unsigned long long	uint64;

int		N,K,kettle[MAX_NUM_OF_KETTLE];

void	input(int& max_kettle)
{
	cin>>N>>K;
	
	max_kettle = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>kettle[i];
		max_kettle = max(max_kettle,kettle[i]);
	}
}

uint64	get_cnt(int n)
{
	uint64	cnt;
	int		i;
	
	for(i=1,cnt=0;i<=N;i++)
	{
		cnt += (uint64)(kettle[i]/n);
	}
	
	return	cnt;
}

int		bin_search(int lo,int hi)
{
	int	mid,cnt;
	
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
	int	max_kettle;
	
	input(max_kettle);
	cout<<bin_search(1,max_kettle)<<endl;
	
	return	0;
}
