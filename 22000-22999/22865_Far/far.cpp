#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE        (100000+1)
#define NUM_OF_HOUSES   3
#define INF             0x7FFFFFFF

typedef pair<int,int>   Path;   // first:to,second:distance
typedef pair<int,int>   State;  // first:-total_distance,second:current_pos

int N,live_pos[NUM_OF_HOUSES];
int M,dist[NUM_OF_HOUSES][MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=0;i<NUM_OF_HOUSES;i++)
    {
        cin>>live_pos[i];
    }

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        int D,E,L;

        cin>>D>>E>>L;

        connected[D].push_back(make_pair(E,L));
        connected[E].push_back(make_pair(D,L));
    }
}

void    dijkstra(int idx)
{
    priority_queue<State>   pq;

    fill(&dist[idx][1],&dist[idx][N+1],INF);
    pq.push(make_pair(0,live_pos[idx]));dist[idx][live_pos[idx]]=0;

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        if( current_dist > dist[idx][current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_dist = current_dist+adj[i].second;

            if( adj_dist < dist[idx][adj_pos] )
            {
                dist[idx][adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_pos));
            }
        }
    }
}

int     get_min_dist(int pos)
{
    int ret = INF;

    for(int i=0;i<NUM_OF_HOUSES;i++)
    {
        ret = min(ret,dist[i][pos]);
    }

    return  ret;
}

int     get_far_pos(void)
{
    int ret,max_dist;

    max_dist = 0;

    for(int i=1;i<=N;i++)
    {
        int current_dist = get_min_dist(i);
        
        if( current_dist > max_dist )
        {
            ret = i;
            max_dist = current_dist;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=0;i<NUM_OF_HOUSES;i++)
    {
        dijkstra(i);
    }

    cout<<get_far_pos()<<'\n';

    return  0;
}