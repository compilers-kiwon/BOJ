#include	<cstdio>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_NUMS	(1000+1)

int	A[MAX_NUM_OF_NUMS],dp1[MAX_NUM_OF_NUMS],dp2[MAX_NUM_OF_NUMS];

int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(int i=1;i<=N;i++)
	{
		int	tmp = 0;
		
		for(int j=1;j<i;j++)
		{
			if( A[j]<A[i] )
			{
				tmp = max(tmp,dp1[j]);
			}
		}
		dp1[i] = tmp+1;
	}
	
	for(int i=N;i>=1;i--)
	{
		int	tmp = 0;
		
		for(int j=N;j>i;j--)
		{
			if( A[j]<A[i] )
			{
				tmp = max(tmp,dp2[j]);
			}
		}
		dp2[i] = tmp+1;
	}
	
	int	max_len = 0;
	
	for(int i=1;i<=N;i++)
	{
		max_len = max(max_len,dp1[i]+dp2[i]-1);
	}
	printf("%d\n",max_len);
	
	return	0;
}
