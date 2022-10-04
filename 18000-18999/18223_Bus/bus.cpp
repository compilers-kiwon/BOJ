#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (5000+1)
#define INF         0x7FFFFFFF

typedef pair<int,int>   Path;   // first:adj_pos,second:distance
typedef pair<int,int>   State;  // first:-total_distance,second:current_pos

int             V,E,P,dp[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>V>>E>>P;

    for(int i=1;i<=E;i++)
    {
        int a,b,c;

        cin>>a>>b>>c;

        connected[a].push_back(make_pair(b,c));
        connected[b].push_back(make_pair(a,c));
    }
}

void    find_shortest_path(void)
{
    priority_queue<State>   pq;

    dp[1] = 0;
    pq.push(make_pair(0,1));

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        if( current_dist > dp[current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_dist = current_dist+adj[i].second;

            if( adj_dist < dp[adj_pos] )
            {
                dp[adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_pos));
            }
        }
    }
}

bool    go_by_way(void)
{
    queue<int>  q;

    for(q.push(V);!q.empty();q.pop())
    {
        int current_pos = q.front();

        if( current_pos == P )
        {
            return  true;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_dist = dp[current_pos]-adj[i].second;

            if( adj_dist == dp[adj_pos] )
            {
                q.push(adj_pos);
            }
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    fill(&dp[1],&dp[V+1],INF);

    find_shortest_path();

    if( go_by_way() == true )
    {
        cout<<"SAVE HIM\n";
    }
    else
    {
        cout<<"GOOD BYE\n";
    }

    return  0;
}