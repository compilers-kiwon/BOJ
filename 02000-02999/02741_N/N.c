#include    <stdio.h>

typedef    unsigned int    uint32;

int    main(void)
{
    uint32    N,i;
    
    scanf("%u",&N);
    
    for(i=1;i<N;i=i+2)
    {
        printf("%u\n%u\n",i,i+1);
    }
    
    if( i == N )
    {
        printf("%u\n",N);
    }
    
    return    0;
}
