#include	<stdio.h>

int	main(void)
{
	unsigned int	T,A,B;
	
	scanf("%u",&T);
	
	while(T>0)
	{
		scanf("%u %u",&A,&B);
		printf("%u\n",A+B);
		T--;
	}
	
	return	0;
}
