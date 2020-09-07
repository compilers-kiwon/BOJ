#include	<iostream>

using namespace	std;

#define	NUM_OF_SACKS	5

int	main(void)
{
	int	c;
	
	scanf("%d",&c);
	
	for(int i=1;i<=c;i++)
	{
		int	max_weight,j;
		
		for(j=1,max_weight=0;j<=NUM_OF_SACKS;j++)
		{
			int	w;
			
			cin>>w;
			max_weight = max(max_weight,w);
		}
		
		printf("Case #%d: %d\n",i,max_weight);
	}
	
	return	0;
}
