#include    <iostream>
#include    <queue>

using namespace std;

typedef priority_queue<int> pq;

void    get_numbers(int size,pq& set)
{
    for(int i=1;i<=size;i++)
    {
        int n;

        cin>>n;
        set.push(n);
    }
}

void    input(pq& A,pq& B)
{
    int nA,nB;

    cin>>nA>>nB;

    get_numbers(nA,A);
    get_numbers(nB,B);
}

void    get_difference(pq& d,pq& included,pq& excluded)
{
    for(;!included.empty()&&!excluded.empty();)
    {
        int a = included.top();
        int b = excluded.top();

        if( a == b )
        {
            included.pop();
            excluded.pop();
        }
        else
        {
            if( a > b )
            {
                included.pop();
                d.push(-a);
            }
            else
            {
                excluded.pop();
            }
        }
    }

    for(;!included.empty();included.pop())
    {
        d.push(-included.top());
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    pq  A,B,D;

    input(A,B);
    get_difference(D,A,B);

    cout<<D.size()<<'\n';

    for(;!D.empty();D.pop())
    {
        cout<<-D.top()<<' ';
    }

    return  0;
}