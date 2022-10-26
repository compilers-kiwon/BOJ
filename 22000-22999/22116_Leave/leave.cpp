#include    <iostream>
#include    <queue>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_DIR     4
#define INF         0x7FFFFFFF

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<int,Pos>   State;  // first:-max_diff,second:Pos

int N,grid[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>grid[row][col];
            dp[row][col] = INF;
        }
    }
}

int     leave_office(void)
{
    priority_queue<State>   pq;

    dp[1][1] = 0;
    pq.push(make_pair(0,make_pair(1,1)));

    for(;!pq.empty();)
    {
        int current_diff = -pq.top().first;
        int current_row = pq.top().second.first;
        int current_col = pq.top().second.second;

        pq.pop();
        
        if( current_row==N && current_col==N )
        {
            break;
        }

        if( current_diff > dp[current_row][current_col] )
        {
            continue;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
            {
                continue;
            }

            int adj_diff = max(current_diff,
                            abs(grid[current_row][current_col]-grid[adj_row][adj_col]));
            
            if( adj_diff < dp[adj_row][adj_col] )
            {
                dp[adj_row][adj_col] = adj_diff;
                pq.push(make_pair(-adj_diff,make_pair(adj_row,adj_col)));
            }
        }
    }

    return  dp[N][N];
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<leave_office()<<'\n';

    return  0;
}