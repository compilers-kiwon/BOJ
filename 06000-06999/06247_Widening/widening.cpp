#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef pair<int,pair<int,int>> Channel;    // first:width,<first:lake1,second:lake2>

int n,m,k,parent[MAX_SIZE];
priority_queue<Channel> pq;

void    input(void)
{
    cin>>n>>m;

    for(int c=1;c<=m;c++)
    {
        int i,j,w;

        cin>>i>>j>>w;
        pq.push(make_pair(w,make_pair(i,j)));
    }

    cin>>k;

    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
    }
}

int     find_parent(int n)
{
    int&    ret = parent[n];

    if( ret != n )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    
    int cnt = 0;

    for(;!pq.empty();pq.pop())
    {
        int width = pq.top().first;
        int lake1 = pq.top().second.first;
        int lake2 = pq.top().second.second;

        int p1 = find_parent(lake1);
        int p2 = find_parent(lake2);

        if( p1 == p2 )
        {
            continue;
        }

        parent[max(p1,p2)] = min(p1,p2);

        if( k > width )
        {
            cnt++;
        }
    }

    cout<<cnt<<'\n';
    
    return  0;
}