#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_CHAPTER	(100+1)
#define	MAX_AVAILABLE_TIME	(10000+1)

int	score_table[MAX_NUM_OF_CHAPTER][MAX_AVAILABLE_TIME];

int		main(void)
{
	int	N,T,K,S,max_score;
	
	scanf("%d %d",&N,&T);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=T;j++)
		{
			score_table[i][j] = -1;
		}
	}
	
	scanf("%d %d",&K,&S);
	score_table[1][K] = S;
	
	for(int i=2;i<=N;i++)
	{
		scanf("%d %d",&K,&S);
		
		score_table[i][K] = max(S,score_table[i-1][K]);
		
		for(int j=0;j<=T;j++)
		{
			if( score_table[i-1][j] != -1 )
			{
				score_table[i][j] = max(score_table[i][j],score_table[i-1][j]);
				
				if( j+K <= T )
				{
					score_table[i][j+K] = max(score_table[i][j+K],score_table[i-1][j]+S);
				}
			}
		}
	}
	
	max_score = 0;
	
	for(int i=1;i<=T;i++)
	{
		max_score = max(max_score,score_table[N][i]);
	}
	
	printf("%d\n",max_score);
	
	return	0;
}
