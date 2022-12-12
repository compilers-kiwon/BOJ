#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (50+1)
#define MAX_DIR     4
#define BLOCKED     0

typedef struct{int r,c,s;}  State;      // r:row,c:col,s:sum
typedef pair<int,int>       Password;   // first:length,second:sum

int         N,M,grid[MAX_SIZE][MAX_SIZE];
int         visited[MAX_SIZE][MAX_SIZE];
Password    p;

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    simulate(int row,int col,int v)
{
    queue<State>    q;
    
    visited[row][col] = v;
    q.push({row,col,0});

    for(int step=0;!q.empty();step++)
    {
        int     max_sum = 0;
        bool    updated = false;

        for(int i=1,size=q.size();i<=size;i++,q.pop())
        {
            int current_row = q.front().r;
            int current_col = q.front().c;

            max_sum = max(max_sum,q.front().s);

            for(int d=0;d<MAX_DIR;d++)
            {
                int adj_row = current_row+adj[d].d_row;
                int adj_col = current_col+adj[d].d_col;

                if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) ||
                        grid[adj_row][adj_col]==BLOCKED || visited[adj_row][adj_col]==v )
                {
                    continue;
                }

                updated = true;
                
                visited[adj_row][adj_col] = v;
                q.push({adj_row,adj_col,grid[row][col]
                                    +grid[adj_row][adj_col]});
            }
        }

        if( updated == false )
        {
            p = max(p,make_pair(step,max_sum));
        }
    }
}

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>grid[row][col];
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 1;

    input();

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] != BLOCKED )
            {
                p = max(p,make_pair(0,2*grid[row][col]));
                simulate(row,col,cnt++);
            }
        }
    }

    cout<<p.second<<'\n';

    return  0;
}