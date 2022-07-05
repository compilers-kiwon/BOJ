#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef long long int   int64;

int64   input(int64* size,int64 power[])
{
    int64   ret = 0;

    scanf("%lld",size);

    for(int64 i=1;i<=*size;i++)
    {
        scanf("%lld",&power[i]);
        ret += power[i];
    }

    return  ret;
}

int64   get_average(int64 size,int64 sum)
{
    int64   ret;

    sum *= 10000;
    ret = (sum/size+5)/10;

    return  ret;
}

int64   get_percentage(int64 size,int64 power[],int64 avg)
{
    int64   cnt = 0;

    for(int64 i=1;i<=size;i++)
    {
        cnt += ((power[i]*1000>avg)?1:0);
    }

    return  ((cnt*100*10000)/size+5)/10;
}

int     main(void)
{
    //cin.tie(NULL);
    //cin.sync_with_stdio(false);

    int T;

    scanf("%d",&T);

    for(int t=1;t<=T;t++)
    {
        int64   N,power[MAX_SIZE],sum_of_power,avg,percentage;

        sum_of_power = input(&N,power);
        avg = get_average(N,sum_of_power);
        percentage = get_percentage(N,power,avg);

        printf("%lld.%03lld %lld.%03lld%%\n",
                    avg/1000,avg%1000,percentage/1000,percentage%1000);
    }

    return  0;
}