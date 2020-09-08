#include	<stdio.h>

typedef	unsigned int	uint32;

int	main(void)
{
	uint32	K,N,M,total_price,result;
	  
	scanf("%u %u %u",&K,&N,&M);
    
    total_price = K*N;
	
    if( total_price > M )
    {
        result = total_price-M;
    }
    else
    {
        result = 0;
    }
    
    printf("%u\n",result);
	
	return	0;
}
