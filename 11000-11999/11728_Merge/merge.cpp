#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000000+1)

int	A[MAX_SIZE],B[MAX_SIZE];

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(int i=1;i<=M;i++)
	{
		scanf("%d",&B[i]);
	}
	
	int	ai,bi;
	
	for(ai=bi=1;ai<=N && bi<=M;)
	{
		if( A[ai] < B[bi] )
		{
			printf("%d ",A[ai++]);
		}
		else if( A[ai] > B[bi] )
		{
			printf("%d ",B[bi++]);
		}
		else
		{
			printf("%d %d ",A[ai++],B[bi++]);
		}
	}
	
	for(;ai<=N;ai++)
	{
		printf("%d ",A[ai]);
	}
	
	for(;bi<=M;bi++)
	{
		printf("%d ",B[bi]);
	}
	puts("");
	
	return	0;
}

