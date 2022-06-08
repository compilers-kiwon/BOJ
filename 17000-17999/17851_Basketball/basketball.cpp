#include    <iostream>
#include    <queue>

using namespace std;

#define NUM_OF_PLAYERS  5

void    input(priority_queue<int>& pq)
{
    for(int i=1;i<=NUM_OF_PLAYERS;i++)
    {
        int n;

        cin>>n;
        pq.push(n);
    }
}

int     compare(priority_queue<int>& pq1,priority_queue<int>& pq2)
{
    int ret = 0;

    for(;!pq1.empty()&&!pq2.empty();pq1.pop(),pq2.pop())
    {
        if( pq1.top() > pq2.top() )
        {
            ret++;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> t1,t2;

    input(t1);input(t2);
    cout<<compare(t1,t2)<<'\n';

    return  0;
}