#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_THINGS	(100+1)

#define	LESS		-1
#define	GREATER		1
#define	NO_RESULT	0

int	weight_table[MAX_NUM_OF_THINGS][MAX_NUM_OF_THINGS];

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		scanf("%d %d",&a,&b);
		weight_table[a][b] = GREATER;
		weight_table[b][a] = LESS;
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( weight_table[i][j] == NO_RESULT )
				{
					if( weight_table[i][k] == LESS && weight_table[k][j] == LESS )
					{
						weight_table[i][j] = LESS;
					}
					else if( weight_table[i][k] == GREATER && weight_table[k][j] == GREATER )
					{
						weight_table[i][j] = GREATER;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		int	cnt = 0;
		
		for(int j=1;j<=N;j++)
		{
			if( weight_table[i][j] == NO_RESULT )
			{
				++cnt;
			}
		}
		cout<<cnt-1<<endl;
	}
	
	return	0;
}
