#include	<iostream>

using namespace	std;

#define	MAX_NUM	(100000+1)

int	visited[MAX_NUM];

int	main(void)
{
	int	STEP,MOD;
	
	for(int i=1;scanf("%d %d",&STEP,&MOD)==2;i++)
	{
		int	cnt,seed;
		
		for(cnt=1,seed=0,visited[0]=i;;cnt++)
		{
			seed = (seed+STEP)%MOD;
			
			if( visited[seed] == i )
			{
				break;
			}
			
			visited[seed] = i;
		}
		
		printf("%10d%10d ",STEP,MOD);
		
		if( cnt == MOD )
		{
			puts("Good Choice\n");
		}
		else
		{
			puts("Bad Choice\n");
		}
	}
	
	return	0;
}
