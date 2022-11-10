#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

typedef pair<int,int>   Path;   // first:adj_node,second:distance_to_adj_node
typedef pair<int,int>   State;  // first:distance_to_current_node,second:current_node

int             N;
bool            visited[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<N;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        connected[u].push_back(make_pair(v,w));
        connected[v].push_back(make_pair(u,w));
    }
}

void    dfs(int current_node,int current_dist,
                        priority_queue<State>& pq)
{
    if( visited[current_node] == true )
    {
        return;
    }

    visited[current_node] = true;
    pq.push(make_pair(current_dist,current_node));

    vector<Path>&   adj = connected[current_node];

    for(int i=0;i<adj.size();i++)
    {
        int&    adj_node = adj[i].first;
        int&    adj_dist = adj[i].second;

        dfs(adj_node,current_dist+adj_dist,pq);
    }
}

void    init_visited(void)
{
    fill(&visited[1],&visited[N+1],false);
}

int     get_farthest_node(int s)
{
    priority_queue<State>   pq;

    init_visited();
    dfs(s,0,pq);

    return  pq.top().second;
}

int     get_second_far_distance(int s)
{
    priority_queue<State>   pq;

    init_visited();
    dfs(s,0,pq);

    pq.pop();
    return  pq.top().first;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int start_node,end_node;

    input();

    start_node = get_farthest_node(1);
    end_node = get_farthest_node(start_node);

    cout<<max(get_second_far_distance(start_node),
                    get_second_far_distance(end_node))<<'\n';

    return  0;
}