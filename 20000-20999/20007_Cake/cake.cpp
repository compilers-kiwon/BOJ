#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    1000
#define INF         0x7FFFFFFF

typedef pair<int,int>   Path;   // first:to,second:distance
typedef pair<int,int>   State;  // first:-distance,second:neighbor

int             N,M,X,Y,dp[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>X>>Y;

    for(int i=1;i<=M;i++)
    {
        int A,B,C;

        cin>>A>>B>>C;

        connected[A].push_back(make_pair(B,C));
        connected[B].push_back(make_pair(A,C));
    }

    fill(&dp[0],&dp[N],INF);
}

void    get_dp(void)
{
    priority_queue<State>   state_q;

    dp[Y] = 0;
    state_q.push(make_pair(0,Y));

    for(;!state_q.empty();)
    {
        int current_distance = -state_q.top().first;
        int current_neighbor = state_q.top().second;

        state_q.pop();

        vector<Path>&   adj = connected[current_neighbor];

        for(int i=0;i<adj.size();i++)
        {
            const int&  adj_neighbor = adj[i].first;
            const int&  adj_distance = adj[i].second;

            if( current_distance+adj_distance < dp[adj_neighbor] )
            {
                dp[adj_neighbor] = current_distance+adj_distance;
                state_q.push(make_pair(-(current_distance+adj_distance),adj_neighbor));
            }
        }
    }
}

int     count_days_for_all_visit(void)
{
    int                 ret;
    priority_queue<int> day;

    for(int i=0;i<N;i++)
    {
        if( dp[i]==INF || dp[i]*2>X )
        {
            return  -1;
        }

        day.push(-(dp[i]*2));
    }

    for(ret=0;!day.empty();ret++)
    {
        int walk = 0;

        for(;!day.empty();day.pop())
        {
            if( walk+(-day.top()) > X )
            {
                break;
            }

            walk += -day.top();
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_dp();

    cout<<count_days_for_all_visit()<<'\n';

    return  0;
}