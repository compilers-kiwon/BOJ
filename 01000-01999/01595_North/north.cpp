#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

typedef pair<int,int>           Path;

#define MAX_SIZE        10000
#define NOT_VISITED     -1
#define DEFAULT_START   1

int             visited[MAX_SIZE+1];
vector<Path>    connected[MAX_SIZE+1];

void    input(void)
{
    for(int u,v,w;scanf("%d %d %d",&u,&v,&w)==3;)
    {
        connected[u].push_back(make_pair(v,w));
        connected[v].push_back(make_pair(u,w));
    }
}

void    init_visited(void)
{
    for(int i=1;i<=MAX_SIZE;i++)
    {
        visited[i] = NOT_VISITED;
    }
}

int     get_farthest_node(int s,int& dist)
{
    int         ret;
    queue<int>  q;

    init_visited();
    q.push(s),visited[s]=0;

    for(dist=-1;!q.empty();q.pop())
    {
        int             current_node = q.front();
        vector<Path>&   adj = connected[current_node];

        if( visited[current_node] > dist )
        {
            ret = current_node;
            dist = visited[current_node];
        }

        for(int i=0;i<adj.size();i++)
        {
            int adj_node = adj[i].first;
            int adj_dist = visited[current_node]+adj[i].second;

            if( visited[adj_node] == NOT_VISITED )
            {
                q.push(adj_node);
                visited[adj_node] = adj_dist;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    int start,end,farthest_dist;
    
    input();
    
    start = get_farthest_node(
                DEFAULT_START,farthest_dist);
    end = get_farthest_node(start,farthest_dist);

    printf("%d\n",farthest_dist);

    return  0;
}