#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)
#define INF         0x7FFFFFFF

typedef pair<int,int>   Path;   // first:adj_pos,second:limitation_of_gold
typedef pair<int,int>   State;  // first:gold_in_hands,second:current_pos

int             N,M,s,e,dp[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>s>>e;

    for(int i=1;i<=M;i++)
    {
        int h1,h2,k;

        cin>>h1>>h2>>k;

        connected[h1].push_back(make_pair(h2,k));
        connected[h2].push_back(make_pair(h1,k));
    }
}

int     move(void)
{
    priority_queue<State>   pq;

    dp[s] = INF;
    pq.push(make_pair(INF,s));

    for(;!pq.empty();)
    {
        int current_gold = pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        if( current_pos == e )
        {
            break;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_gold = min(current_gold,adj[i].second);

            if( adj_gold > dp[adj_pos] )
            {
                dp[adj_pos] = adj_gold;
                pq.push(make_pair(adj_gold,adj_pos));
            }
        }
    }

    return  dp[e];
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<move()<<'\n';

    return  0;
}