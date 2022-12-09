#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)
#define NONE        0x7FFFFFFF

typedef pair<int,int>   Path;   // first:adj_pos,second:distance
typedef pair<int,int>   State;  // first:-total_distance,second:current_pos

int             N,M,X,Y,Z,dp[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;
        connected[u].push_back(make_pair(v,w));
    }

    cin>>X>>Y>>Z;
}

int     find_shortest_path(int from,int to,int avoid)
{
    priority_queue<State>   pq;

    fill(&dp[1],&dp[N+1],NONE);
    dp[from]=0;pq.push(make_pair(0,from));

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        if( current_pos == to )
        {
            break;
        }

        if( current_dist > dp[current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_dist = current_dist+adj[i].second;

            if( adj_pos!=avoid && adj_dist<dp[adj_pos] )
            {
                dp[adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_pos));
            }
        }
    }

    return  ((dp[to]==NONE)?-1:dp[to]);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int XtoY,YtoZ,XtoZwithoutY;

    XtoY = find_shortest_path(X,Y,NONE);
    YtoZ = find_shortest_path(Y,Z,NONE);
    XtoZwithoutY = find_shortest_path(X,Z,Y);

    cout<<((XtoY==-1||YtoZ==-1)?
            -1:XtoY+YtoZ)<<' '<<XtoZwithoutY<<'\n';

    return  0;
}