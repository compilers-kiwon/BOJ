#include    <iostream>
#include    <queue>

using namespace std;

#define POSITIVE    0
#define ZERO        1
#define NEGATIVE    2
#define MAX_TYPE    3

typedef long long int   int64;

priority_queue<int64>   num[MAX_TYPE];

void    input(void)
{
    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int64   t;

        cin>>t;

        if( t > 0 )
        {
            num[POSITIVE].push(t);
        }
        else if( t < 0 )
        {
            num[NEGATIVE].push(-t);
        }
        else
        {
            num[ZERO].push(t);
        }
    }
}

int64   get_positive_score(void)
{
    int64                   ret;
    priority_queue<int64>&  pq = num[POSITIVE];

    for(ret=0;pq.size()>=2;)
    {
        int64   n1,n2;

        n1=pq.top();pq.pop();
        n2=pq.top();pq.pop();

        if( n1==1 || n2==1 )
        {
            pq.push(n1);
            pq.push(n2);

            break;
        }

        ret += n1*n2;
    }

    for(;!pq.empty();pq.pop())
    {
        ret += pq.top();
    }

    return  ret;
}

int64   get_negative_score(void)
{
    int64                   ret;
    priority_queue<int64>&  pq = num[NEGATIVE];

    for(ret=0;pq.size()>=2;)
    {
        int64   n1,n2;

        n1=pq.top();pq.pop();
        n2=pq.top();pq.pop();

        ret += n1*n2;
    }

    if( !pq.empty() && num[ZERO].empty() )
    {
        ret -= pq.top();
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_positive_score()+get_negative_score()<<'\n';

    return  0;
}