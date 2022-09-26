#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

int N,M,R,visited[MAX_SIZE];
priority_queue<int> connected[MAX_SIZE];

void    bfs(void)
{
    int cnt = 0;
    queue<int>  q;

    q.push(R);
    visited[R] = ++cnt;

    for(;!q.empty();q.pop())
    {
        int current_node = q.front();

        for(priority_queue<int>& adj=connected[current_node];!adj.empty();adj.pop())
        {
            int adj_node = -adj.top();

            if( visited[adj_node] == 0 )
            {
                q.push(adj_node);
                visited[adj_node] = ++cnt;
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

void    print(void)
{
    for(int i=1;i<=N;i++)
    {
        cout<<visited[i]<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    bfs();
    print();    

    return  0;
}