#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define INF         0x7FFFFFFF

typedef pair<int,int>   Path;   // first:adj,second:distance
typedef pair<int,int>   State;  // first:-total_distance,second:current_pos

int             N,M,K,dp[MAX_SIZE];
vector<int>     friends;
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;
    
    for(int i=1;i<=N;i++)
    {
        connected[i].clear();
    }
    
    friends.clear();

    for(int i=1;i<=M;i++)
    {
        int a,b,c;

        cin>>a>>b>>c;

        connected[a].push_back(make_pair(b,c));
        connected[b].push_back(make_pair(a,c));
    }

    cin>>K;

    for(int i=1;i<=K;i++)
    {
        int r;

        cin>>r;
        friends.push_back(r);
    }
}

int     get_distance(int s)
{
    int                     ret = 0;
    priority_queue<State>   pq;

    fill(&dp[1],&dp[N+1],INF);

    dp[s] = 0;
    pq.push(make_pair(0,s));

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

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

    for(int i=0;i<friends.size();i++)
    {
        ret += dp[friends[i]]; 
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int min_distance,start;

        input();
        min_distance = INF;

        for(int i=1;i<=N;i++)
        {
            int d = get_distance(i);

            if( d < min_distance )
            {
                start = i;
                min_distance = d;
            }
        }

        cout<<start<<'\n';
    }

    return  0;
}