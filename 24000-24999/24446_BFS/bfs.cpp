#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

int         N,M,R,depth[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    bfs(void)
{
    queue<int>  q;

    for(q.push(R),depth[R]=0;!q.empty();q.pop())
    {
        int             current_node = q.front();
        vector<int>&    adj=connected[current_node];
        
        for(int i=0;i<adj.size();i++)
        {
            int adj_node = adj[i];

            if( depth[adj_node] == -1 )
            {
                q.push(adj_node);
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

        connected[u].push_back(v);
        connected[v].push_back(u);
    }
}

void    print(void)
{
    for(int i=1;i<=N;i++)
    {
        cout<<depth[i]<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    fill(&depth[1],&depth[N+1],-1);

    bfs();
    print();    

    return  0;
}