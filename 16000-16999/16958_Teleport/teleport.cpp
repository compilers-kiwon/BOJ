#include    <iostream>
#include    <vector>
#include    <queue>
#include    <cmath>

using namespace std;

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<int,int>   Path;   // first:adj_city,second:distance
typedef pair<int,int>   Query;  // first:fromt,second:to
typedef pair<int,int>   State;  // first:-total_distance,second:current_city

#define MAX_SIZE    (1000+1)
#define INF         0x7FFFFFFF

#define get_distance(p1,p2) (abs((p1).first-(p2).first)+abs((p1).second-(p2).second))

int     N,T,M,dp[MAX_SIZE];
Pos     city[MAX_SIZE];
bool    teleport[MAX_SIZE];

vector<Path>    connected[MAX_SIZE];
vector<Query>   q;

void    input(void)
{
    cin>>N>>T;

    for(int i=1;i<=N;i++)
    {
        int s,x,y;

        cin>>s>>x>>y;

        city[i] = make_pair(x,y);
        teleport[i] = ((s==1)?true:false);
    }

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        int A,B;

        cin>>A>>B;
        q.push_back(make_pair(A,B));
    }
}

void    get_connected(void)
{
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            Pos&    p1 = city[i];
            Pos&    p2 = city[j];
            int     d = ((teleport[i]&&teleport[j])?
                            min(T,get_distance(p1,p2)):get_distance(p1,p2));

            connected[i].push_back(make_pair(j,d));
            connected[j].push_back(make_pair(i,d));
        }
    }
}

int     find_shortest_path(int from,int to)
{
    priority_queue<State>   pq;

    dp[from] = 0;
    pq.push(make_pair(0,from));

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_city = pq.top().second;

        pq.pop();

        if( current_city == to )
        {
            break;
        }

        if( current_dist > dp[current_city] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_city];

        for(int i=0;i<adj.size();i++)
        {
            int adj_city = adj[i].first;
            int adj_dist = current_dist+adj[i].second;

            if( adj_dist < dp[adj_city] )
            {
                dp[adj_city] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_city));
            }
        }
    }

    return  dp[to];
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_connected();

    for(int i=0;i<q.size();i++)
    {
        fill(&dp[1],&dp[N+1],INF);
        cout<<find_shortest_path(q[i].first,q[i].second)<<'\n';
    }

    return  0;
}