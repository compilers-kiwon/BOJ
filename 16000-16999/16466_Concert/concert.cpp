#include    <iostream>
#include    <queue>

using namespace std;

#define min_number(pq)  (-((pq).top()))

void    input(priority_queue<int>& pq)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int A;

        cin>>A;
        pq.push(-A);
    }
}

int     find_smallest_number(priority_queue<int>& pq)
{
    int ret;

    for(int i=1;;i++)
    {
        if( pq.empty() || i<min_number(pq) )
        {
            ret = i;
            break;
        }

        pq.pop();
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> pq;

    input(pq);
    cout<<find_smallest_number(pq)<<'\n';

    return  0;
}