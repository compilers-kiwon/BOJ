#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	PATTERN_H	'-'
#define	PATTERN_V	'|'
#define	EMPTY		' '

int	main(void)
{
	char	floor[MAX_SIZE][MAX_SIZE+1];
	int		N,M,cnt;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&floor[i][1]);
	}
	
	cnt = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( floor[row][col] != EMPTY )
			{
				cnt++;
				
				if( floor[row][col] == PATTERN_H )
				{
					for(int tmp=col+1;tmp<=M;tmp++)
					{
						if( floor[row][tmp] != PATTERN_H )
						{
							break;
						}
						
						floor[row][tmp] = EMPTY;
					}
				}
				else
				{
					for(int tmp=row+1;tmp<=N;tmp++)
					{
						if( floor[tmp][col] != PATTERN_V )
						{
							break;
						}
						
						floor[tmp][col] = EMPTY;
					}
				}
				
				floor[row][col] = EMPTY;
			}
		}
	}
	printf("%d\n",cnt);
	
	return	0;
}
