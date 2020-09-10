#include	<stdio.h>

typedef	unsigned int	uint32;

int	main(void)
{
	uint32	T,A,B,i;
	
	scanf("%u",&T);
	
	for(i=1;i<=T;i++)
	{
		scanf("%u %u",&A,&B);
		printf("Case #%u: %u\n",i,A+B);	
	}
	return	0;	
}
