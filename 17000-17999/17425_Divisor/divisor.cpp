#include    <iostream>

using namespace std;

#define MAX_SIZE    1000000

typedef long long int   int64;

int64   sum_of_divisors[MAX_SIZE+1],acc_sum[MAX_SIZE+1];

void    init(void)
{
    fill(&sum_of_divisors[1],&sum_of_divisors[MAX_SIZE+1],1);

    for(int64 i=2;i<=MAX_SIZE;i++)
    {
        for(int64 j=i;j<=MAX_SIZE;j+=i)
        {
            sum_of_divisors[j] += i;
        }
    }

    for(int i=1;i<=MAX_SIZE;i++)
    {
        acc_sum[i] = acc_sum[i-1]+sum_of_divisors[i];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    init();
    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int N;

        cin>>N;
        cout<<acc_sum[N]<<'\n';
    }

    return  0;
}