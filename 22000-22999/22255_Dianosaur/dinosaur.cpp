#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_STEPS   3
#define WALL        -1
#define INF         0x7FFFFFFF
#define FIRST_STEP  1

typedef pair<int,int>   Pos;    // first:row(d_row),second:col(d_col)

typedef struct{
    int row,col,step,power;
} State;

int         N,M;
int         dp[MAX_SIZE][MAX_SIZE][MAX_STEPS];
int         grid[MAX_SIZE][MAX_SIZE];
Pos         S,E;
vector<Pos> adj[MAX_STEPS];

#define get_dp(s)       (dp[(s).row][(s).col][(s).step])
#define set_dp(s)       {dp[(s).row][(s).col][(s).step]=(s).power;}

#define new_state(s,d)  \
    {(s).row+(d).first,(s).col+(d).second,((s).step+1)%MAX_STEPS,(s).power}

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N>>M
        >>S.first>>S.second
        >>E.first>>E.second;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>grid[row][col];
            fill(&dp[row][col][0],
                    &dp[row][col][MAX_STEPS],INF);
        }
    }
}

void    init_adj(void)
{
    adj[0].push_back(make_pair(-1,0));
    adj[0].push_back(make_pair(1,0));
    adj[0].push_back(make_pair(0,-1));
    adj[0].push_back(make_pair(0,1));

    adj[1].push_back(make_pair(-1,0));
    adj[1].push_back(make_pair(1,0));

    adj[2].push_back(make_pair(0,-1));
    adj[2].push_back(make_pair(0,1));
}

int     simulate(void)
{
    int ret;
    queue<State>    q;

    dp[S.first][S.second][FIRST_STEP] = 0;
    q.push({S.first,S.second,FIRST_STEP,0});

    for(ret=INF;!q.empty();q.pop())
    {
        State   current = q.front();
        
        if( current.row==E.first
                && current.col==E.second )
        {
            ret = min(ret,current.power);
            continue;
        }

        if( current.power > get_dp(current) )
        {
            continue;
        }

        vector<Pos>&    d = adj[current.step];

        for(int i=0;i<d.size();i++)
        {
            State   next = new_state(current,d[i]);
            
            if( !IN_RANGE(1,next.row,N)
                || !IN_RANGE(1,next.col,M)
                || grid[next.row][next.col] == WALL )
            {
                continue;
            }

            next.power += grid[next.row][next.col];

            if( next.power < get_dp(next) )
            {
                q.push(next);set_dp(next);
            }
        }
    }

    return  ((ret==INF)?-1:ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();init_adj();
    cout<<simulate()<<'\n';

    return  0;
}