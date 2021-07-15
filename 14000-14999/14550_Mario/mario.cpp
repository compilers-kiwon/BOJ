#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (200+1)
#define MAX_TURN    (MAX_SIZE+1)
#define INF         (MAX_SIZE*(-10000))

int N,S,T,score[MAX_SIZE+1],dp[MAX_SIZE+1][MAX_TURN];

typedef struct{int p,s,t;}  State;  // p:pos, s:score, t:turn

bool    input(void)
{
    cin>>N;

    if( N == 0 )
    {
        return  false;
    }

    cin>>S>>T;
    score[N+1] = 0;

    for(int i=1;i<=N;i++)
    {
        cin>>score[i];
    }
    
    for(int pos=1;pos<=N+1;pos++)
    {
        for(int turn=1;turn<=T;turn++)
        {
            dp[pos][turn] = INF;
        }
    }

    return  true;
}

int     simulate(void)
{
    int             ret;
    State           st;
    queue<State>    state_q;

    st.p = st.s = st.t = 0;
    state_q.push(st);

    for(ret=INF;!state_q.empty();state_q.pop())
    {
        State   current;

        current = state_q.front();

        if( current.p == N+1 )
        {
            ret = max(ret,current.s);
            continue;
        }

        if( current.t == T )
        {
            continue;
        }

        for(int offset=1;offset<=S;offset++)
        {
            State   next;

            next.p = min(N+1,current.p+offset);
            next.s = current.s+score[next.p];
            next.t = current.t+1;

            if( next.s > dp[next.p][next.t] )
            {
                dp[next.p][next.t] = next.s;
                state_q.push(next);
            }
        }
    }
    
    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        if( input() == false )
        {
            break;
        }

        cout<<simulate()<<'\n';
    }

    return  0;
}