#include    <iostream>

using namespace std;

#define MAX_SIZE    8

typedef unsigned long long  uint64;

static uint64   addr[MAX_SIZE],N;

int input(void)
{
    int M;

    scanf("%d",&M);

    if( M == 1 )
    {
        scanf("%llu.%llu.%llu.%llu.%llu.%llu.%llu.%llu",
            &addr[7],&addr[6],&addr[5],&addr[4],&addr[3],&addr[2],&addr[1],&addr[0]);
    }
    else
    {
        scanf("%llu",&N);
    }

    return  M;
}

int main(void)
{
    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        if( input() == 1 )
        {
            uint64  n = 0;

            for(int i=0;i<MAX_SIZE;i++)
            {
                n |= addr[i]<<(i*8);
            }

            printf("%llu\n",n);
        }
        else
        {
            for(int i=MAX_SIZE-1;i>=0;i--)
            {
                printf("%llu%c",(N>>(i*8))&0xFFULL,(i==0)?'\n':'.');
            }
        }
    }

    return  0;
}