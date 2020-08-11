#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_EVENTS	(400+1)

#define	DIRECT		-1
#define	NO_RELATION	0
#define	INVERSE		1

int	history[MAX_NUM_OF_EVENTS][MAX_NUM_OF_EVENTS];

int	main(void)
{
	int	n,k,s;
	
	scanf("%d %d",&n,&k);
	
	for(int i=1;i<=k;i++)
	{
		int	former,later;
		
		scanf("%d %d",&former,&later);
		
		history[former][later] = DIRECT;
		history[later][former] = INVERSE;
	}
	
	for(int m=1;m<=n;m++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if( history[i][j] == NO_RELATION )
				{
					if( history[i][m] != NO_RELATION && history[i][m] == history[m][j] )
					{
						history[i][j] = history[i][m];
						history[j][i] = -history[i][m];
					}
				}
			}
		}
	}
	
	scanf("%d",&s);
	
	for(int i=1;i<=s;i++)
	{
		int	event1,event2;
		
		scanf("%d %d",&event1,&event2);
		printf("%d\n",history[event1][event2]);
	}
	return	0;
}
