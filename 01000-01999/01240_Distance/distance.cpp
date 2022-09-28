#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)
#define NOT_VISITED -1

typedef pair<int,int>   Query;  // first:node1,second:node2
typedef pair<int,int>   Path;   // first:to,second:distance

int             N,M,visited[MAX_SIZE][MAX_SIZE];
vector<Path>    connected[MAX_SIZE];
vector<Query>   queries;

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<N;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        connected[u].push_back(make_pair(v,w));
        connected[v].push_back(make_pair(u,w));
    }

    for(int i=1;i<=M;i++)
    {
        Query   q;

        cin>>q.first>>q.second;
        queries.push_back(q);
    }
}

void    get_distance(void)
{
    for(int s=1;s<=N;s++)
    {
        queue<int>  q;
        
        fill(&visited[s][1],&visited[s][N+1],NOT_VISITED);

        q.push(s);
        visited[s][s] = 0;

        for(;!q.empty();q.pop())
        {
            int current = q.front();
            vector<Path>& adj = connected[current];

            for(int i=0;i<adj.size();i++)
            {
                int&    adj_node = adj[i].first;
                int&    adj_dist = adj[i].second;

                if( visited[s][adj_node] == NOT_VISITED )
                {
                    q.push(adj_node);
                    visited[s][adj_node] = visited[s][current]+adj_dist;
                }
            }
        }
    }
}

void    print(void)
{
    for(int i=0;i<queries.size();i++)
    {
        cout<<visited[queries[i].first][queries[i].second]<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_distance();
    print();

    return  0;
}