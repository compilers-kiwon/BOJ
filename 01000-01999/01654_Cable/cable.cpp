#include	<cstdio>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_LAN_CABLE	(10000+1)

typedef	unsigned long long	uint64;

vector<uint64>	cable(MAX_NUM_OF_LAN_CABLE);

uint64	K,N;

uint64	get_num_of_cables_with_this_len(uint64 this_len)
{
	uint64	cnt,i;
	
	for(i=1,cnt=0;i<=K;i++)
	{
		cnt += cable[i]/this_len;
	}
	return	cnt;
}

uint64	cut_cable(uint64 min_len,uint64 max_len)
{
	uint64	lo,hi,mid;
	
	lo = min_len;
	hi = max_len+1;
	
	while(lo+1<hi)
	{
		mid = (lo+hi)/2;
		
		if( get_num_of_cables_with_this_len(mid) >= N )
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
	scanf("%llu %llu",&K,&N);
	
	uint64	max_len,i;
	
	for(i=1,max_len=0;i<=K;i++)
	{
		scanf("%llu",&cable[i]);
		
		max_len = max(max_len,cable[i]);
	}
	
	printf("%llu\n",cut_cable(1,max_len));
	
	return	0;
}
