#include	<cstdio>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX(a,b)	((a)>(b)?(a):(b))

int	map[MAX_SIZE][MAX_SIZE];

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			map[i][j] += MAX(map[i-1][j],map[i][j-1]);
		}
	}
	printf("%d\n",map[N][M]);
	
	return	0;
}
