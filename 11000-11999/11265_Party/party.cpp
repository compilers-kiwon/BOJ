#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PARTY_PLACE	(500+1)

int	N,M;
int	d[MAX_NUM_OF_PARTY_PLACE][MAX_NUM_OF_PARTY_PLACE];

int	main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&d[i][j]);
		}
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( d[i][j] > d[i][k]+d[k][j] )
				{
					d[i][j] = d[i][k]+d[k][j];
				}
			}
		}
	}
	
	for(int i=1;i<=M;i++)
	{
		int	A,B,C;
		
		scanf("%d %d %d",&A,&B,&C);
		
		if( d[A][B] <= C )
		{
			puts("Enjoy other party");
		}
		else
		{
			puts("Stay here");
		}
	}
	
	return	0;
}
