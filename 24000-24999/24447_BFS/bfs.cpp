#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

typedef long long int       int64;
typedef priority_queue<int> pq;

int     N,M,R;
int64   depth[MAX_SIZE],visited[MAX_SIZE];
pq      connected[MAX_SIZE];

void    bfs(void)
{
    int cnt = 1;
    queue<int>  q;

    for(q.push(R),depth[R]=0,visited[R]=cnt++;!q.empty();q.pop())
    {
        int current_node = q.front();
        pq& adj=connected[current_node];
        
        for(;!adj.empty();adj.pop())
        {
            int adj_node = -adj.top();

            if( visited[adj_node] == 0 )
            {
                q.push(adj_node);
                visited[adj_node] = cnt++;
                depth[adj_node] = depth[current_node]+1;
            }
        }
    }
}

void    input(void)
{
    cin>>N>>M>>R;

    for(int i=1;i<=M;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].push(-v);
        connected[v].push(-u);
    }
}

int64   get_sum(void)
{
    int64   ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret += (int64)depth[i]*(int64)visited[i];
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    bfs();
    cout<<get_sum()<<'\n';    

    return  0;
}