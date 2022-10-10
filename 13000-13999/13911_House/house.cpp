#include    <iostream>
#include    <vector>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_SIZE    (10000+1)
#define INF         0x7FFFFFFF

int             V,E,M,S,x,y;
int             dp_x[MAX_SIZE],dp_y[MAX_SIZE];
map<int,int>    connected[MAX_SIZE];    // [from][to] = distance
vector<int>     store_x,store_y;

typedef pair<int,int>           State;  // first:-total_distance,second:current_pos
typedef map<int,int>::iterator  Iter;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>V>>E;

    for(int i=1;i<=E;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        if( connected[u][v]==0 || w<connected[u][v] )
        {
            connected[u][v] = connected[v][u] = w;
        }
    }

    cin>>M>>x;

    for(int i=1;i<=M;i++)
    {
        int s;

        cin>>s;
        store_x.push_back(s);
    }

    cin>>S>>y;

    for(int i=1;i<=S;i++)
    {
        int s;

        cin>>s;
        store_y.push_back(s);
    }
}

void    find_shortest_path(vector<int>& starts,int dp[])
{
    priority_queue<State>   pq;

    fill(&dp[1],&dp[V+1],INF);

    for(int i=0;i<starts.size();i++)
    {
        dp[starts[i]] = 0;
        pq.push(make_pair(0,starts[i]));
    }

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        if( current_dist > dp[current_pos] )
        {
            continue;
        }

        map<int,int>&   adj = connected[current_pos];
        
        for(Iter it=adj.begin();it!=adj.end();it++)
        {
            int adj_pos = it->first;
            int adj_dist = current_dist+it->second;

            if( adj_dist < dp[adj_pos] )
            {
                dp[adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_pos));
            }
        }
    }
}

int     find_house(void)
{
    int ret = INF;

    for(int i=1;i<=V;i++)
    {
        int&    dx = dp_x[i];
        int&    dy = dp_y[i];

        if( !IN_RANGE(1,dx,x) || !IN_RANGE(1,dy,y) )
        {
            continue;
        }

        ret = min(ret,dx+dy);
    }

    return  ((ret==INF)?-1:ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    find_shortest_path(store_x,dp_x);
    find_shortest_path(store_y,dp_y);

    cout<<find_house()<<'\n';

    return  0;
}