#include	<cstdio>
#include	<iostream>

using namespace std;

#define	MAX_LEN	(1000+1)

int		N,num[MAX_LEN],sum[MAX_LEN];

int	main(void)
{
	int	answer = 0;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&num[i]);
	}
	
	for(int	i=1;i<=N;i++)
	{
		int	max_sum = 0;
		
		for(int j=i-1;j>=1;j--)
		{
			if( num[j] < num[i] )
			{
				max_sum = max(max_sum,sum[j]);
			}
		}
		sum[i] = max_sum+num[i];
		answer = max(answer,sum[i]);
	}
	printf("%d\n",answer);
	
	return	0;
}
