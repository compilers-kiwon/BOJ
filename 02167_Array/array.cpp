#include	<cstdio>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(300+1)

int	N,M,K;
int	arr[MAX_SIZE][MAX_SIZE];

int	main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	
	scanf("%d",&K);
	
	while(K>0)
	{
		int	sum = 0;
		int	i,j,x,y;
		
		scanf("%d %d %d %d",&i,&j,&x,&y);
		
		for(int row=i;row<=x;row++)
		{
			for(int col=j;col<=y;col++)
			{
				sum = sum+arr[row][col];
			}
		}
		printf("%d\n",sum);
		K--;
	}
	return	0;
}
