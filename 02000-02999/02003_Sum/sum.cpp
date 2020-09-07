#include	<iostream>

using namespace	std;

#define	MAX_LEN	(10000+1)

int	A[MAX_LEN];

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
	}
	
	int	cnt,sum;
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		sum = 0;
		
		for(int j=i;j<=N;j++)
		{
			sum += A[j];
			
			if( sum > M )
			{
				break;
			}
			else if( sum == M )
			{
				++cnt;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	
	return	0;
}
