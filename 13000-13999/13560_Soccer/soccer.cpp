#include	<cstdio>
#include	<algorithm>

using namespace std;

#define	MAX_NUM_OF_TEAMS	(10000+1)

typedef	unsigned long long	uint64;

uint64	cache[MAX_NUM_OF_TEAMS];
int		team_point[MAX_NUM_OF_TEAMS];

int	main(void)
{
	int		n,result,i;
	uint64	sum;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&team_point[i]);	
	}
	
	sort(&team_point[1],&team_point[n+1]);
	
	if( n == 2 )
	{
		if( team_point[1] == 0 && team_point[2] == 1 )
		{
			result = 1;
		}
		else
		{
			result = -1;
		}
		printf("%d\n",result);
		
		return	0;
	}
	
	cache[1] = 0;
	cache[2] = 1;
	sum = (uint64)(team_point[1]+team_point[2]);
	
	if( !((uint64)team_point[1] >= cache[1] && sum >= cache[2]) )
	{
		printf("-1\n");
		return	0;
	}
	
	result = 1;
	
	int j,k;
	
	for(j=3,k=1;j<=n-1;j++,k++)
	{
		cache[j] = cache[j-1]*((uint64)j)/((uint64)k);
		sum = sum+(uint64)team_point[j];
		
		if( sum < cache[j] )
		{
			result = -1;
			break;
		}
	}
	
	if( result == 1 )
	{
		cache[j] = cache[j-1]*((uint64)j)/((uint64)k);
		sum = sum+(uint64)team_point[j];
		
		if( cache[j] != sum )
		{
			result = -1;
		}
	}
	printf("%d\n",result);
	
	return	0;	
}
