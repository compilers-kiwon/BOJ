#include    <stdio.h>

typedef    unsigned int    uint32;

int    main(void)
{
    uint32    N,i;

    scanf("%u",&N);
    
    for(i=N;i>2;i=i-3)
    {
        printf("%u\n%u\n%u\n",i,i-1,i-2);
    }
    
    if( i == 2 )
    {
        puts("2\n1");
    }
    else if( i== 1 )
    {
        puts("1");
    }
    
    return    0;
}
