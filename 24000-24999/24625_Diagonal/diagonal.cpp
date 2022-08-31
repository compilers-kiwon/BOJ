#include    <iostream>
#include    <queue>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (100000+1)

typedef long long int   int64;

int64   sum[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    int64   max_sum;
    priority_queue<int64>   pq;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int64   a;

        cin>>a;
        pq.push(a);        
    }

    for(int i=1;i<=n;i++,pq.pop())
    {
        sum[i] = sum[i-1]+pq.top();
    }

    max_sum = -1000000000LL*MAX_SIZE;

    for(int i=1;i<=sqrt(n);i++)
    {
        max_sum = max(max_sum,sum[i]);
    }

    cout<<max_sum<<'\n';

    return  0;
}