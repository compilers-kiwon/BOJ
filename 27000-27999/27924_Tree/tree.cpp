#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (200000+1)
#define INF         0x7FFFFFFF

#define THIEF       0
#define POLICE_1    1
#define POLICE_2    2
#define MAX_NUM     3

static int  N,a,b,c,dp[MAX_NUM][MAX_SIZE];
static vector<int>  connected[MAX_SIZE];
static vector<int>  leaf_node;

#define TRUE    1
#define FALSE   0

#define is_leaf_node(node)  (connected[(node)].size()==1)

int input(void)
{
    cin>>N;

    for(int i=1;i<N;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].push_back(v);
        connected[v].push_back(u);
    }

    cin>>a>>b>>c;

    for(int i=0;i<MAX_NUM;i++)
    {
        fill(&dp[i][1],&dp[i][N+1],INF);
    }

    return  0;
}

int get_leaf_node(void)
{
    for(int i=1;i<=N;i++)
    {
        if( is_leaf_node(i) )
        {
            leaf_node.push_back(i);
        }
    }

    return  0;
}

int bfs(int pos,int idx)
{
    queue<int>  q;

    for(q.push(pos),dp[idx][pos]=0;!q.empty();q.pop())
    {
        int current_pos = q.front();

        for(int i=0;i<connected[current_pos].size();i++)
        {
            int&    adj_pos = connected[current_pos][i];

            if( dp[idx][adj_pos] == INF )
            {
                q.push(adj_pos);
                dp[idx][adj_pos] = dp[idx][current_pos]+1;
            }
        }
    }

    return  0;
}

int escape(void)
{
    for(int i=0;i<leaf_node.size();i++)
    {
        int&    thief_time = dp[THIEF][leaf_node[i]];
        int&    police1_time = dp[POLICE_1][leaf_node[i]];
        int&    police2_time = dp[POLICE_2][leaf_node[i]];

        if( thief_time<police1_time && thief_time<police2_time )
        {
            return  TRUE;
        }
    }

    return  FALSE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_leaf_node();

    bfs(a,THIEF);
    bfs(b,POLICE_1);
    bfs(c,POLICE_2);

    cout<<((escape()==TRUE)?"YES":"NO")<<'\n';

    return  0;
}