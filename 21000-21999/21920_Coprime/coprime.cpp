#include    <iostream>

using namespace std;

#define MAX_SIZE    (500000+1)

int     N,num[MAX_SIZE],X;

void    input(void)
{
    scanf("%d",&N);

    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
    }

    scanf("%d",&X);
}

int     get_lcd(int i)
{
    int big = max(X,num[i]);
    int small = min(X,num[i]);

    for(int mod=big%small;mod!=0;mod=big%small)
    {
        big = small;
        small = mod;
    }

    return  small;
}

int     main(void)
{
    input();

    int     cnt = 0;
    double  sum = 0.0;

    for(int i=1;i<=N;i++)
    {
        if( get_lcd(i) == 1 )
        {
            sum += (double)num[i];
            cnt++;
        }
    }

    printf("%.06f\n",sum/(double)cnt);

    return  0;
}