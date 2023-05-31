#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<int,int>   State;
typedef priority_queue<State>   pq;

#define MAX_SIZE    (100+1)

int input(pq& q)
{
    int n,m;
    int cnt[MAX_SIZE] = {0,};

    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int v;

            cin>>v;
            cnt[j] += v;
        }
    }

    for(int i=1;i<=m;i++)
    {
        q.push({cnt[i],-i});
    }

    return  0;
}

int print(pq& q)
{
    for(;!q.empty();q.pop())
    {
        cout<<-q.top().second<<' ';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    pq  q;

    input(q);
    print(q);

    return  0;
}