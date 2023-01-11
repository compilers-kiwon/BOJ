#include    <stdio.h>

#define AVAILABLE   90
#define IN_BUF_SIZE 10
#define DAY_POS     2

int main(void)
{
    int N,cnt,i;

    scanf("%d",&N);

    for(i=cnt=0;i<N;i++)
    {
        int     x;
        char    buf[IN_BUF_SIZE];

        scanf("%s",buf);
        sscanf(&buf[DAY_POS],"%d",&x);
        cnt += (x<=AVAILABLE)?1:0;
    }

    printf("%d\n",cnt);

    return  0;
}