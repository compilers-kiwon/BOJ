#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

typedef long long int   int64;

int     N,M;
int64   D,E,h[MAX_SIZE],dp_up[MAX_SIZE],dp_down[MAX_SIZE];
bool    visited_up[MAX_SIZE],visited_down[MAX_SIZE];

typedef pair<int,int64> Path;   // first:adj_pos,second:distance
typedef pair<int64,int> State;  // first:-total_distance,second:current_pos

vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>D>>E;

    for(int i=1;i<=N;i++)
    {
        cin>>h[i];
    }

    for(int i=1;i<=M;i++)
    {
        int     a,b;
        int64   n;

        cin>>a>>b>>n;

        connected[a].push_back(make_pair(b,n));
        connected[b].push_back(make_pair(a,n));
    }
}

void    move(int start,bool visited[],int64 dp[])
{
    priority_queue<State>   pq;

    visited[start] = true;
    pq.push(make_pair(0,start));
    dp[start] = 0;

    for(;!pq.empty();)
    {
        int64   current_dist = -pq.top().first;
        int     current_pos = pq.top().second;

        pq.pop();

        if( current_dist > dp[current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int     adj_pos = adj[i].first;

            if( h[current_pos] >= h[adj_pos] )
            {
                continue;
            }

            int64   adj_dist = current_dist+adj[i].second;

            if( visited[adj_pos]==false || adj_dist<dp[adj_pos] )
            {
                dp[adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_pos));
                visited[adj_pos] = true;
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    move(1,visited_up,dp_up);
    move(N,visited_down,dp_down);

    bool    found = false;
    int64   max_val;

    for(int i=1;i<=N;i++)
    {
        if( visited_up[i]==false || visited_down[i]==false )
        {
            continue;
        }

        if( found==false || (h[i]*E-(dp_up[i]+dp_down[i])*D)>max_val )
        {
            found = true;
            max_val = h[i]*E-(dp_up[i]+dp_down[i])*D;
        }
    }

    if( found == false )
    {
        cout<<"Impossible\n";
    }
    else
    {
        cout<<max_val<<'\n';
    }

    return  0;
}