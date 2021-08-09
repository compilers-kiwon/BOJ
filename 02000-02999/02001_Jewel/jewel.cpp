#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_JEWEL   14
#define NONE        -1

typedef pair<int,int>   Bridge; // first:to,second:weight

int             n,m,K,jewel[MAX_SIZE];
int             dp[1<<MAX_JEWEL][MAX_SIZE]; // [visited_jewels][current_island]
vector<Bridge>  connected[MAX_SIZE];

typedef struct{int visited,current,num_of_jewels;}  State;

void    input(void)
{
    cin>>n>>m>>K;
    fill(&jewel[1],&jewel[n+1],NONE);

    for(int i=0;i<K;i++)
    {
        int a;

        cin>>a;
        jewel[a] = i;
    }

    for(int i=0;i<(1<<K);i++)
    {
        fill(&dp[i][1],&dp[i][n+1],NONE);
    }

    for(int i=1;i<=m;i++)
    {
        int a,b,c;

        cin>>a>>b>>c;

        connected[a].push_back(make_pair(b,c));
        connected[b].push_back(make_pair(a,c));
    }
}

int     simulate(void)
{
    int             ret;
    State           s;
    queue<State>    state_q;

    s.visited=s.num_of_jewels=0;s.current=1;

    dp[0][1] = 0;
    state_q.push(s);

    for(ret=0;!state_q.empty();state_q.pop())
    {
        int visited = state_q.front().visited;
        int current = state_q.front().current;
        int num_of_jewels = state_q.front().num_of_jewels;
        
        if( current == 1 )
        {
            ret = max(ret,num_of_jewels);
        }

        vector<Bridge>& adj = connected[current];
        
        if( jewel[current]!=NONE && (visited&(1<<jewel[current]))==0 )  // get
        {
            s.current = current;
            s.visited = visited|(1<<jewel[current]);
            s.num_of_jewels = num_of_jewels+1;

            if( s.num_of_jewels > dp[s.visited][s.current] )
            {
                dp[s.visited][s.current] = s.num_of_jewels;
                state_q.push(s);
            }
        }

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_island = adj[i].first;
            int&    adj_weight = adj[i].second;

            if( num_of_jewels > adj_weight )
            {
                continue;
            }

            s.current = adj_island;
            s.visited = visited;
            s.num_of_jewels = num_of_jewels;

            if( s.num_of_jewels > dp[s.visited][s.current] )
            {
                dp[s.visited][s.current] = s.num_of_jewels;
                state_q.push(s);
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