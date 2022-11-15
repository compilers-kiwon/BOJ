#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_USERS   3
#define INF         0x7FFFFFFF

typedef pair<int,int>   Used;
typedef pair<int,int>   Path;
typedef pair<int,int>   State;

int n,m,dp[MAX_USERS+1][MAX_SIZE];
int user[MAX_USERS+1],step[MAX_USERS+1][MAX_SIZE];

vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        connected[u].push_back(make_pair(v,w));
        connected[v].push_back(make_pair(u,w));
    }

    for(int i=1;i<=MAX_USERS;i++)
    {
        cin>>user[i];
    }
}

void    find_shortest_path(int user_idx)
{
    int&    start = user[user_idx];
    priority_queue<State>   pq;

    for(pq.push(make_pair(0,start)),dp[user_idx][start]=0;!pq.empty();)
    {
        int current_cost = -pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        if( current_cost > dp[user_idx][current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_cost = adj[i].second+current_cost;

            if( adj_cost < dp[user_idx][adj_pos] )
            {
                dp[user_idx][adj_pos] = adj_cost;
                step[user_idx][adj_pos] = current_pos;
                pq.push(make_pair(-adj_cost,adj_pos));
            }
        }
    }
}

int     find_switch_of_min_cost(int& min_cost)
{
    int ret;
    
    min_cost = INF;
    
    for(int i=1;i<=n;i++)
    {
        int sum = 0;

        for(int u=1;u<=MAX_USERS;u++)
        {
            if( dp[u][i] == INF )
            {
                sum = INF;
                break;
            }

            sum += dp[u][i];
        }

        if( sum < min_cost )
        {
            ret = i;
            min_cost = sum;
        }
    }

    return  ret;
}

void    get_used_switches(int sw,vector<Used>& u)
{
    for(int i=1;i<=MAX_USERS;i++)
    {
        for(int current_pos=sw;current_pos!=user[i];current_pos=step[i][current_pos])
        {
            u.push_back(make_pair(current_pos,step[i][current_pos]));
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=1;i<=MAX_USERS;i++)
    {
        fill(&dp[i][1],&dp[i][n+1],INF);
        find_shortest_path(i);
    }

    int             min_cost,min_cost_switch;
    vector<Used>    used;

    min_cost_switch = find_switch_of_min_cost(min_cost);
    get_used_switches(min_cost_switch,used);

    cout<<min_cost<<' '<<used.size()<<'\n';

    for(int i=0;i<used.size();i++)
    {
        cout<<used[i].first<<' '<<used[i].second<<'\n';
    }

    return  0;
}