#include	<stdio.h>

int	main(void)
{
	int	i,max_value,max_value_index;
	
	max_value = 0;
	
	for(i=1;i<=9;i++)
	{
		int	n;
		
		scanf("%d",&n);
				
		if( n > max_value )
		{
			max_value = n;
			max_value_index = i;
		}
	}
	printf("%d\n%d\n",max_value,max_value_index);
	
	return	0;
}
