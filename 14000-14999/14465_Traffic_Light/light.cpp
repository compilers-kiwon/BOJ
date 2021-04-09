#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

int N,K,B,sum_of_broken[MAX_SIZE];

void    input(priority_queue<int>& broken_light)
{
    cin>>N>>K>>B;

    for(int i=1;i<=B;i++)
    {
        int n;

        cin>>n;
        broken_light.push(-n);
    }
}

void    get_sum_of_broken_light(priority_queue<int>& broken_light)
{
    for(int i=1;i<=N;i++)
    {
        sum_of_broken[i] = sum_of_broken[i-1];

        if( i == (-broken_light.top()) )
        {
            sum_of_broken[i]++;
            broken_light.pop();
        }
    }
}

int     get_min_num_of_boken_light(void)
{
    int ret = N;

    for(int h=1,t=K;t<=N;h++,t++)
    {
        ret = min(ret,sum_of_broken[t]-sum_of_broken[h-1]);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> bq;

    input(bq);
    get_sum_of_broken_light(bq);

    cout<<get_min_num_of_boken_light()<<'\n';

    return  0;
}