#include	<cstdio>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_ROPE	(100000+1)

int	rope[MAX_NUM_OF_ROPE];

int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&rope[i]);
	}
	
	sort(&rope[1],&rope[N+1]);
	
	int	max_weight = 0;
	
	for(int i=N,j=1;i>=1;i--,j++)
	{
		max_weight = max(max_weight,j*rope[i]);
	}
	printf("%d\n",max_weight);
	
	return	0;
}
