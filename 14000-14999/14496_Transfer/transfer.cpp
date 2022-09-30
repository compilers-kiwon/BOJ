#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)
#define NOT_VISITED -1

int a,b,N,M,visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    init(void)
{
    cin>>a>>b>>N>>M;
    fill(&visited[1],&visited[N+1],NOT_VISITED);

    for(int i=1;i<=M;i++)
    {
        int c,d;

        cin>>c>>d;

        connected[c].push_back(d);
        connected[d].push_back(c);
    }
}

int     transfer(void)
{
    queue<int>  q;

    for(visited[a]=0,q.push(a);!q.empty();q.pop())
    {
        int current = q.front();
        vector<int>& adj = connected[current];

        if( current == b )
        {
            break;
        }

        for(int i=0;i<adj.size();i++)
        {
            if( visited[adj[i]] == NOT_VISITED )
            {
                q.push(adj[i]);
                visited[adj[i]] = visited[current]+1;
            }
        }
    }

    return  visited[b];
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    cout<<transfer()<<'\n';

    return  0;
}