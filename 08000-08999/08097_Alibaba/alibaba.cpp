#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    100
#define MAX_RULE    (10+1)
#define INF         0x7FFFFFFF

typedef struct{int z,s,m;}  State;
typedef pair<State,State>   Rule;   // first:input,second:output

int     r,dp[MAX_SIZE+1][MAX_SIZE+1][MAX_SIZE+1];
State   init_state,final_state;
Rule    rule[MAX_RULE];

void    input(void)
{
    cin>>init_state.z>>init_state.s>>init_state.m;
    cin>>final_state.z>>final_state.s>>final_state.m;
    
    cin>>r;

    for(int i=1;i<=r;i++)
    {
        State&  input = rule[i].first;
        State&  output = rule[i].second;

        cin>>input.z>>input.s>>input.m>>output.z>>output.s>>output.m;
    }
}

void    init_dp(void)
{
    for(int z=0;z<=MAX_SIZE;z++)
    {
        for(int s=0;s<=MAX_SIZE;s++)
        {
            for(int m=0;m<=MAX_SIZE;m++)
            {
                dp[z][s][m] = INF;
            }
        }
    }
}

int     get_dp(void)
{
    int             ret;
    queue<State>    state_q;

    state_q.push(init_state);
    dp[init_state.z][init_state.s][init_state.m] = 0;
    
    for(ret=INF;!state_q.empty();state_q.pop())
    {
        State   current = state_q.front();
        
        if( current.z>=final_state.z && current.s>=final_state.s && current.m>=final_state.m )
        {
            ret = dp[current.z][current.s][current.m];
            break;
        }

        for(int i=1;i<=r;i++)
        {
            State&  input = rule[i].first;
            State&  output = rule[i].second;

            if( current.z<input.z || current.s<input.s || current.m<input.m )
            {
                continue;
            }

            State   adj;

            adj.z = current.z-input.z+output.z;
            adj.s = current.s-input.s+output.s;
            adj.m = current.m-input.m+output.m;

            if( adj.z>MAX_SIZE || adj.z>MAX_SIZE || adj.m>MAX_SIZE )
            {
                continue;
            }
            
            if( dp[current.z][current.s][current.m]+1 < dp[adj.z][adj.s][adj.m] )
            {
                state_q.push(adj);
                dp[adj.z][adj.s][adj.m] = dp[current.z][current.s][current.m]+1;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int d;

    cin>>d;

    for(;d>0;d--)
    {
        int result;

        input();
        init_dp();

        result = get_dp();

        if( result == INF )
        {
            cout<<"NIE\n";
        }
        else
        {
            cout<<result<<'\n';
        }
    }

    return  0;    
}