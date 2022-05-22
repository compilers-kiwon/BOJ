#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    pair<int64,int64>   sum,e;

    for(sum=make_pair(0,0);scanf("%lld.%lld",&e.first,&e.second)==2;)
    {
        sum.first += e.first;
        sum.second += e.second;
    }

    printf("%lld.%02d\n",sum.first+(sum.second/100),(int)(sum.second%100));

    return  0;
}