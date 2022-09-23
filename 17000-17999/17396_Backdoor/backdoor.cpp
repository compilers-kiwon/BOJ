#include    <iostream>
#include    <queue>
#include    <vector>

using namespace std;

#define MAX_SIZE    100000
#define INF         (100000LL*100000LL+1LL)

typedef long long int   int64;
typedef pair<int,int64> Path;   // first:to,second:time
typedef pair<int64,int> State;  // first:-total_time,second:pos

int             N,M;
int64           dp[MAX_SIZE];
bool            visible[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        cin>>visible[i];
    }

    visible[N-1] = false;

    for(int i=1;i<=M;i++)
    {
        int     a,b;
        int64   t;

        cin>>a>>b>>t;
        
        if( visible[a]==true || visible[b]==true )
        {
            continue;
        }

        connected[a].push_back(make_pair(b,t));
        connected[b].push_back(make_pair(a,t));
    }

    fill(&dp[0],&dp[N],INF);
}

int64   move(void)
{
    priority_queue<State>   pq;

    dp[0] = 0;
    pq.push(make_pair(0,0));

    for(;!pq.empty();)
    {
        int64   current_time = -pq.top().first;
        int     current_pos = pq.top().second;

        pq.pop();

        if( current_time > dp[current_pos] ) continue;
        
        if( current_pos == N-1 )
        {
            break;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_pos = adj[i].first;
            int64   adj_time = current_time+adj[i].second;
            
            if( visible[adj_pos] == true )
            {
                continue;
            }

            if( adj_time < dp[adj_pos] )
            {
                dp[adj_pos] = adj_time;
                pq.push(make_pair(-adj_time,adj_pos));
            }
        }
    }

    return  ((dp[N-1]==INF)?-1:dp[N-1]);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<move()<<'\n';

    return  0;
}