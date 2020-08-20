#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_ICE_CREAM	(200+1)

bool	no_mix_table[MAX_NUM_OF_ICE_CREAM][MAX_NUM_OF_ICE_CREAM];

int	main(void)
{
	int	N,M,cnt;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	ic1,ic2;
		
		scanf("%d %d",&ic1,&ic2);
		no_mix_table[ic1][ic2] = no_mix_table[ic2][ic1] = true;
	}
	
	cnt = 0;
	
	for(int ic1=1;ic1<=N-2;ic1++)
	{
		for(int ic2=ic1+1;ic2<=N-1;ic2++)
		{
			if( no_mix_table[ic1][ic2] == true )
			{
				continue;
			}
			
			for(int ic3=ic2+1;ic3<=N;ic3++)
			{
				if( no_mix_table[ic1][ic3] == true || no_mix_table[ic2][ic3] == true )
				{
					continue;
				}
				
				++cnt;
			}
		}
	}
	
	printf("%d\n",cnt);
	
	return	0;
}
