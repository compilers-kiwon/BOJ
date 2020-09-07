#include	<stdio.h>

int	main(void)
{
	int	i,max_score,max_score_index;
	
	max_score = 0;
	
	for(i=1;i<=5;i++)
	{
		int	a,b,c,d,sum;
		
		scanf("%d %d %d %d",&a,&b,&c,&d);
		sum = a+b+c+d;
		
		if( sum > max_score )
		{
			max_score = sum;
			max_score_index = i;
		}
	}
	printf("%d %d\n",max_score_index,max_score);
	
	return	0;
}
