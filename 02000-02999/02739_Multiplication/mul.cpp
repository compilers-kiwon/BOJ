#include    <stdio.h>

int    main(void)
{
    int    N,i,value;
    
    scanf("%d",&N);
    
    for(i=1,value=N;i<=9;i++,value=value+N)
    {
        printf("%d * %d = %d\n",N,i,value);
    }
    return    0;
}
