#include    <iostream>
#include    <vector>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_SIZE    (10000+1)

typedef pair<int,int>   Path;   // first:to,second:time 
typedef pair<int,int>   State;  // first:current,second:total_time

int             n,m,s,e,dp[MAX_SIZE];
map<int,bool>   visited[MAX_SIZE];  // visited[to][from]
vector<Path>    f[MAX_SIZE],b[MAX_SIZE];

void    input(void)
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        f[u].push_back(make_pair(v,w));
        b[v].push_back(make_pair(u,w));
    }

    cin>>s>>e;
}

int     get_critical_time(void)
{
    queue<State>    q;

    dp[s] = 0;
    q.push(make_pair(s,0));

    for(;!q.empty();q.pop())
    {
        int current_pos = q.front().first;
        int current_time = q.front().second;

        if( current_pos==e || current_time<dp[current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = f[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_pos = adj[i].first;
            int&    adj_time = adj[i].second;

            if( current_time+adj_time > dp[adj_pos] )
            {
                dp[adj_pos] = current_time+adj_time;
                q.push(make_pair(adj_pos,current_time+adj_time));
            }
        }
    }

    return  dp[e];
}

int     get_num_of_critical_paths(void)
{
    int         ret;
    queue<State> q;

    visited[e][0] = true;

    for(q.push(make_pair(e,dp[e])),ret=0;!q.empty();q.pop())
    {
        int current_pos = q.front().first;
        int current_time = q.front().second;

        if( current_pos == s )
        {
            continue;
        }

        vector<Path>&   adj = b[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_pos = adj[i].first;
            int&    adj_time = adj[i].second;

            if( visited[adj_pos][current_pos]==false 
                            && current_time-adj_time==dp[adj_pos] )
            {
                ret++;
                visited[adj_pos][current_pos] = true;
                q.push(make_pair(adj_pos,current_time-adj_time));
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
    fill(&dp[1],&dp[n+1],-1);

    cout<<get_critical_time()<<'\n';
    cout<<get_num_of_critical_paths()<<'\n';

    return  0;
}