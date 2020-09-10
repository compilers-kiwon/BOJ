#include	<cstdio>
#include	<algorithm>

using namespace std;

#define	MAX_NUM_OF_FILES	(500+1)

int	cost[MAX_NUM_OF_FILES],merge_result[MAX_NUM_OF_FILES][MAX_NUM_OF_FILES];

int	merge_file(int start_index,int end_index)
{
	if( merge_result[start_index][end_index] != -1 )
	{
		return	merge_result[start_index][end_index];
	}
	
	if( start_index == end_index )
	{
		return	0;
	}
	
	int	result = 0x7FFFFFFF;
	
	for(int	i=start_index;i<end_index;i++)
	{
		int	merge;
		
		merge = merge_file(start_index,i)+merge_file(i+1,end_index)+(cost[end_index]-cost[start_index-1]);
		result = min(result,merge);
	}
	
	merge_result[start_index][end_index] = result;
	
	return	result;
}

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	K,i,j;
		
		scanf("%d",&K);
		
		for(i=1;i<=K;i++)
		{
			for(j=1;j<=K;j++)
			{
				merge_result[i][j] = -1;
			}
		}
		
		for(cost[0]=0,i=1;i<=K;i++)
		{
			int	s;
			
			scanf("%d",&s);
			cost[i] = cost[i-1]+s;
		}
		
		int	min = merge_file(1,K);
		
		printf("%d\n",min);
		
		T--;
	}
	return	0;
}
