#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_LOCAL	(10000+1)
#define	MAX_BUDGET			(1000000000+1)

int	N,budget;
int	local_budget[MAX_NUM_OF_LOCAL];

bool	check_budget(int upper_limit)
{
	int sum,i;
	
	for(sum=0,i=1;i<=N;i++)
	{
		sum += min(local_budget[i],upper_limit);
	}
	
	return	(sum<=budget);
}

int		give_budget_to_local(int max_local_budget)
{
	int	lo,mid,hi;
	
	lo = 1;
	hi = max_local_budget+1;
	
	while(lo+1<hi)
	{
		mid = (lo+hi)/2;
		
		if( check_budget(mid) == true )
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
	int	max_local;
	
	scanf("%d",&N);
	max_local = 0;
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&local_budget[i]);
		max_local = max(max_local,local_budget[i]);
	}
	
	scanf("%d",&budget);
	printf("%d\n",give_budget_to_local(max_local));
	
	return	0;
}
