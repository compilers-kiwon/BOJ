#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)
#define INF         0x7FFFFFFF
#define MAX_DIR     4

#define FREE    '.'
#define ROCK    '#'

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int,int>   Pos;    // first:row,second:col

const struct{
    int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int     C,R,dp[MAX_SIZE][MAX_SIZE];
char    grid[MAX_SIZE][MAX_SIZE+1];

void    input(Pos& s)
{
    cin>>C>>R;

    for(int row=1;row<=R;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=C;col++)
        {
            if( grid[row][col] == FREE )
            {
                s = make_pair(row,col);
            }
        }
    }
}

void    init_dp(void)
{
    for(int row=1;row<=R;row++)
    {
        fill(&dp[row][1],&dp[row][C+1],INF);
    }
}

int     find_farthest_pos(Pos& s)
{
    int         ret = 0;
    queue<Pos>  q;

    q.push(s);
    init_dp();
    dp[s.first][s.second] = 0;

    for(;!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) 
                || grid[adj_row][adj_col]==ROCK || dp[adj_row][adj_col]!=INF )
            {
                continue;
            }

            q.push(make_pair(adj_row,adj_col));
            dp[adj_row][adj_col] = dp[current_row][current_col]+1;

            ret = dp[adj_row][adj_col];
            s = make_pair(adj_row,adj_col);
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {   
        Pos p;
        int d;

        input(p);
        d = find_farthest_pos(p);

        if( d != 0 )
        {
            d = find_farthest_pos(p);
        }

        cout<<"Maximum rope length is "<<d<<".\n";
    }

    return  0;
}