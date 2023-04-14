#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)

#define INF     0x7FFFFFFF
#define NONE    -1

typedef pair<int,int>   Path;   // first:to,second:time
typedef pair<int,int>   State;  // first:-time,second:pos

static int  V,M,J,S,dp_from_j[MAX_SIZE],dp_from_s[MAX_SIZE];
static vector<Path> connected[MAX_SIZE];

#define is_reachable(pos)   (dp_from_j[(pos)]!=INF&&dp_from_s[(pos)]!=INF)

int input(void)
{
    cin>>V>>M;

    for(int i=1;i<=M;i++)
    {
        int a,b,c;

        cin>>a>>b>>c;

        connected[a].push_back(make_pair(b,c));
        connected[b].push_back(make_pair(a,c));
    }

    cin>>J>>S;

    fill(&dp_from_j[1],&dp_from_j[V+1],INF);
    fill(&dp_from_s[1],&dp_from_s[V+1],INF);

    return  0;
}

int get_arrival_time(int from,int dp[])
{
    priority_queue<State>   pq;

    dp[from] = 0;
    pq.push(make_pair(0,from));

    for(;!pq.empty();)
    {
        int current_time = -pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_time = current_time+adj[i].second;

            if( adj_time < dp[adj_pos] )
            {
                dp[adj_pos] = adj_time;
                pq.push(make_pair(-adj_time,adj_pos));
            }
        }
    }

    dp[from] = INF;

    return  0;
}

int get_best_pos(void)
{
    int ret = NONE;
    int min_time = INF;
    
    vector<int> candidates;

    for(int i=1;i<=V;i++)
    {
        if( !is_reachable(i) )
        {
            continue;
        }
        
        int total_time = dp_from_j[i]+dp_from_s[i];

        if( total_time <= min_time )
        {
            if( total_time < min_time )
            {
                candidates.clear();
            }

            candidates.push_back(i);
            min_time = total_time;
        }
    }

    for(int i=0;i<candidates.size();i++)
    {
        int pos = candidates[i];

        if( dp_from_j[pos] > dp_from_s[pos] )
        {
            continue;
        }

        if( ret==NONE || dp_from_j[pos]<dp_from_j[ret] )
        {
            ret = pos;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    get_arrival_time(J,dp_from_j);
    get_arrival_time(S,dp_from_s);

    cout<<get_best_pos()<<'\n';

    return  0;
}