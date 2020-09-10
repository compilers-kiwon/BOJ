#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_NUMBERS	100000

int	A[MAX_NUM_OF_NUMBERS+1];

int	main(void)
{
	int			N,M;
		
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		scanf("%d",&n);
		A[i] = A[i-1]+n;
	}
	
	scanf("%d",&M);
	
	for(int q=1;q<=M;q++)
	{
		int	i,j;
		
		scanf("%d %d",&i,&j);
		printf("%d\n",A[j]-A[i-1]);
	}
	
	return	0;
}
