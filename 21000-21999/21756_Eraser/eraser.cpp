#include    <iostream>
#include    <queue>

using namespace std;

#define is_even(n)  ((n)%2==0)

#define erase_odd_idx(idx,q)    \
    {(is_even((idx)))?(q).push((q).front()):(void)0;(q).pop();}

void    input(queue<int>& q)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        q.push(i);
    }
}

int     simulate(queue<int>& q)
{
    for(;q.size()!=1;)
    {
        for(int i=1,size=q.size();i<=size;i++)
        {
            erase_odd_idx(i,q);
        }
    }

    return  q.front();
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int>  q;

    input(q);
    cout<<simulate(q)<<'\n';

    return  0;
}