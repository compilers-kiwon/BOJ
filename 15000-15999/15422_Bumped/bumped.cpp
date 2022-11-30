#include    <iostream>
#include    <vector>
#include    <queue>
#include    <set>

using namespace std;

#define MAX_SIZE    50000

typedef unsigned int        uint32;
typedef pair<int,uint32>    Path;

typedef struct{int c,f;uint32 g;}  State;   // c:city,f:used flight,g:gas

int     n,m,f,s,t;
uint32  dp[2][MAX_SIZE];

vector<Path>    connected[MAX_SIZE];
set<int>        flight[MAX_SIZE];

void    input(void)
{
    cin>>n>>m>>f>>s>>t;

    for(int k=1;k<=m;k++)
    {
        int     i,j;
        uint32  c;

        cin>>i>>j>>c;

        connected[i].push_back(make_pair(j,c));
        connected[j].push_back(make_pair(i,c));
    }

    for(int i=1;i<=f;i++)
    {
        int u,v;

        cin>>u>>v;
        flight[u].insert(v);
    }

    fill(&dp[0][0],&dp[0][n],0xFFFFFFFF);
    fill(&dp[1][0],&dp[1][n],0xFFFFFFFF);
}

uint32  move(void)
{
    uint32          ret;
    queue<State>    q;

    dp[0][s] = 0;
    q.push({s,0,0});

    for(ret=0xFFFFFFFF;!q.empty();q.pop())
    {
        int     current_city = q.front().c;
        int     num_of_flight = q.front().f;
        uint32  current_gas = q.front().g;

        if( current_city == t )
        {
            ret = min(ret,current_gas);
            continue;
        }

        if( current_gas > dp[num_of_flight][current_city] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_city];

        for(int i=0;i<adj.size();i++)
        {
            int     adj_city = adj[i].first;
            uint32  adj_gas = current_gas+adj[i].second;

            if( adj_gas < dp[num_of_flight][adj_city] )
            {
                dp[num_of_flight][adj_city] = adj_gas;
                q.push({adj_city,num_of_flight,adj_gas});
            }
        }

        if( num_of_flight == 0 )
        {
            set<int>&   f = flight[current_city];

            for(set<int>::iterator it=f.begin();it!=f.end();it++)
            {
                int adj_city = *it;

                if( current_gas < dp[num_of_flight+1][adj_city] )
                {
                    dp[num_of_flight+1][adj_city] = current_gas;
                    q.push({adj_city,num_of_flight+1,current_gas});
                }
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
    cout<<move()<<'\n';

    return  0;
}