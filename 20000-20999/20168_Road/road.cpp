#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (10+1)
#define MAX_MONEY   (10000+1)
#define INF         0x7FFFFFFF

typedef pair<int,int>   Path;   // first:to,second:cost
typedef pair<int,int>   Pos;    // first:money_in_hands,second:pos
typedef pair<int,Pos>   State;  // first:-max_cost,second:Pos

int N,M,A,B,C,dp[MAX_SIZE][MAX_MONEY];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>A>>B>>C;

    for(int i=1;i<=M;i++)
    {
        int p1,p2,cost;

        cin>>p1>>p2>>cost;

        connected[p1].push_back(make_pair(p2,cost));
        connected[p2].push_back(make_pair(p1,cost));
    }
}

void    init_dp(void)
{
    for(int i=1;i<=N;i++)
    {
        fill(&dp[i][0],&dp[i][MAX_MONEY],INF);
    }
}

int     simulate(void)
{
    int ret = -1;
    priority_queue<State>   pq;

    init_dp();

    dp[A][C] = 0;
    pq.push(make_pair(0,make_pair(C,A)));

    for(;!pq.empty();)
    {
        int max_cost = -pq.top().first;
        int current_money = pq.top().second.first;
        int current_pos = pq.top().second.second;

        pq.pop();

        if( current_pos == B )
        {
            ret = max_cost;
            break;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_cost = adj[i].second;
            int adj_money = current_money-adj_cost;

            if( adj_money < 0 )
            {
                continue;
            }

            if( max(max_cost,adj_cost) < dp[adj_pos][adj_money] )
            {
                dp[adj_pos][adj_money] = max(max_cost,adj_cost);
                pq.push(make_pair(-max(max_cost,adj_cost),make_pair(adj_money,adj_pos)));
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
    cout<<simulate()<<'\n';

    return  0;
}