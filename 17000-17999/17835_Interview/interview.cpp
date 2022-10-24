#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)
#define INF         1000000000000L

typedef long long int   int64;

typedef pair<int,int64> Path;   // first:adj_city,second:distance
typedef pair<int64,int> State;  // first:-total_distance,second:current_city

int             N,M,K;
int64           dp[MAX_SIZE];
vector<int>     interview_location;
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>K;

    for(int i=1;i<=M;i++)
    {
        int     U,V;
        int64   C;

        cin>>U>>V>>C;
        connected[V].push_back(make_pair(U,C));
    }

    for(int i=1;i<=K;i++)
    {
        int n;

        cin>>n;
        interview_location.push_back(n);
    }
}

void    init(priority_queue<State>& pq)
{
    fill(&dp[1],&dp[N+1],INF);

    for(int i=0;i<interview_location.size();i++)
    {
        int&    n = interview_location[i];

        dp[n] = 0;
        pq.push(make_pair(0,n));
    }
}

void    simulate(void)
{
    priority_queue<State>   pq;

    for(init(pq);!pq.empty();)
    {
        int64   current_dist = -pq.top().first;
        int     current_city = pq.top().second;
        
        pq.pop();

        if( current_dist > dp[current_city] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_city];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_city = adj[i].first;
            int64   adj_dist = current_dist+adj[i].second;

            if( adj_dist < dp[adj_city] )
            {
                dp[adj_city] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_city));
            }
        }
    }
}

int     find_farthest_city(int64& dist)
{
    int ret;
    
    dist = -1;

    for(int i=1;i<=N;i++)
    {
        if( dp[i] > dist )
        {
            ret = i;
            dist = dp[i];
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    int     f_city;
    int64   f_dist;

    f_city = find_farthest_city(f_dist);
    cout<<f_city<<'\n'<<f_dist<<'\n';

    return  0;
}