#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    200000
#define INF         0x7FFFFFFF
#define FLIP(n)     (((n)+1)%2)

int         N,E,dp[MAX_SIZE][2];
vector<int> connected[MAX_SIZE][2];

typedef struct{int n,t,b;}  State;

void    input(void)
{
    cin>>N>>E;

    for(int i=1;i<=E;i++)
    {
        int A,B,V;

        cin>>A>>B>>V;

        connected[A][V].push_back(B);
        connected[B][V].push_back(A);
    }

    for(int i=0;i<N;i++)
    {
        dp[i][0] = dp[i][1] = INF;
    }
}

int     go(void)
{
    State           s;
    queue<State>    state_q;

    state_q.push({0,0,0});
    state_q.push({0,0,1});

    for(dp[0][0]=dp[0][1]=0;!state_q.empty();state_q.pop())
    {
        int current_node = state_q.front().n;
        int current_time = state_q.front().t;
        int current_value = state_q.front().b;

        if( current_node == N-1 )
        {
            continue;
        }

        vector<int>&    adj = connected[current_node][current_value];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_node = adj[i];

            if( current_time+1 < dp[adj_node][FLIP(current_value)] )
            {
                dp[adj_node][FLIP(current_value)] = current_time+1;
                state_q.push({adj_node,current_time+1,FLIP(current_value)});
            }
        }
    }

    int ret = min(dp[N-1][0],dp[N-1][1]);

    return  ((ret==INF)?-1:ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<go()<<'\n';

    return  0;
}