#include	<stdio.h>

#define	MAX_NUM_OF_FILES	(1000+1)

typedef	unsigned long long	uint64;

int	main(void)
{
	int		N,i;
	uint64	file[MAX_NUM_OF_FILES],cluster;
	uint64	num_of_clusters;
	
	scanf("%d",&N);
	
	for(i=1;i<=N;i++)
	{
		scanf("%llu",&file[i]);
	}
	
	scanf("%llu",&cluster);
	
	for(i=1,num_of_clusters=0;i<=N;i++)
	{	
		num_of_clusters += (file[i]/cluster)+((file[i]%cluster==0)?0:1);
	}
	printf("%llu\n",num_of_clusters*cluster);
	
	return	0;
}
