#include    <iostream>
#include    <vector>
#include    <queue>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (200000+1)
#define INF         0x7FFFFFFF

typedef pair<int,int>   Path;   // first:adj,second:distance
typedef pair<int,int>   State;  // first:-total_distance,second:pos

int             N,M,S,E,next_pos[MAX_SIZE],dp[MAX_SIZE];
bool            visited[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    go_back(int current_pos,int current_dist)
{
    if( current_dist == 0 )
    {
        return;
    }

    vector<Path>&   adj = connected[current_pos];

    for(int i=0;i<adj.size();i++)
    {
        int adj_pos = adj[i].first;
        int adj_dist = current_dist-adj[i].second;

        if( dp[adj_pos]==adj_dist && current_pos<next_pos[adj_pos] )
        {
            next_pos[adj_pos] = current_pos;
            go_back(adj_pos,adj_dist);
        }
    }
}

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int A,B,C;

        cin>>A>>B>>C;

        connected[A].push_back(make_pair(B,C));
        connected[B].push_back(make_pair(A,C));
    }

    cin>>S>>E;

    for(int i=1;i<=N;i++)
    {
        sort(connected[i].begin(),connected[i].end());
    }
}

int     walk(int from,int to,bool flag_to_update_visit)
{
    int                     ret;
    priority_queue<State>   pq;

    fill(&dp[1],&dp[N+1],INF);
    fill(&next_pos[1],&next_pos[N+1],INF);

    pq.push(make_pair(0,from));dp[from]=0;

    for(visited[from]=true,visited[to]=false;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_pos = pq.top().second;
        
        pq.pop();

        if( current_dist > dp[current_pos] )
        {
            continue;
        }

        if( current_pos == to )
        {
            ret = current_dist;
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_dist = current_dist+adj[i].second;

            if( visited[adj_pos]==false && adj_dist<dp[adj_pos] )
            {
                dp[adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_pos));
            }
        }
    }

    if( flag_to_update_visit == true )
    {
        go_back(to,ret);

        for(int pos=from;pos!=INF;pos=next_pos[pos])
        {
            visited[pos] = true;
        }
    }
    
    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<walk(S,E,true)+walk(E,S,false)<<'\n';

    return  0;
}