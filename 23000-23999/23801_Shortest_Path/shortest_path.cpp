#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

typedef long long int               int64;
typedef pair<int,int64>             Path;   // first:adj_city,second:weight
typedef pair<int64,pair<int,int>>   State;  // first:-sum_of_weight,<first:current_city,second:visited>

#define MAX_SIZE    (100000+1)
#define INF         0x7FFFFFFFFFFFFFFF

#define HAVE_NOT_VISITED    0
#define HAVE_VISITED        1

int             N,M,X,Z,P;
int64           dp[2][MAX_SIZE];
bool            have_to_visit[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int     u,v;
        int64   w;

        cin>>u>>v>>w;

        connected[u].push_back(make_pair(v,w));
        connected[v].push_back(make_pair(u,w));
    }

    fill(&dp[HAVE_NOT_VISITED][1],&dp[HAVE_NOT_VISITED][N+1],INF);
    fill(&dp[HAVE_VISITED][1],&dp[HAVE_VISITED][N+1],INF);

    cin>>X>>Z>>P;

    for(int i=1;i<=P;i++)
    {
        int Y;

        cin>>Y;
        have_to_visit[Y] = true;
    }
}

int64   find_shortest_path(void)
{
    int64                   ret;
    priority_queue<State>   state_q;

    dp[HAVE_NOT_VISITED][X] = 0;
    state_q.push(make_pair(0,make_pair(X,HAVE_NOT_VISITED)));

    for(ret=-1;!state_q.empty();)
    {
        int64   current_weight = -state_q.top().first;
        int     current_city = state_q.top().second.first;
        int     current_visited = state_q.top().second.second;

        state_q.pop();

        if( current_city==Z && current_visited==HAVE_VISITED )
        {
            ret = current_weight;
            break;
        }

        vector<Path>&   adj = connected[current_city];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_city = adj[i].first;
            int64&  adj_weight = adj[i].second;
            int     adj_visit = current_visited|(have_to_visit[adj_city]?HAVE_VISITED:HAVE_NOT_VISITED);

            if( current_weight+adj_weight < dp[adj_visit][adj_city] )
            {
                dp[adj_visit][adj_city] = current_weight+adj_weight;
                state_q.push(make_pair(-(current_weight+adj_weight),make_pair(adj_city,adj_visit)));
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<find_shortest_path()<<'\n';

    return  0;
}