#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (2000+1)
#define MAX_DIR     4
#define NONE        -1

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int     N,M,K,grid[MAX_SIZE][MAX_SIZE];
int     scared[MAX_SIZE][MAX_SIZE];
bool    visited[MAX_SIZE][MAX_SIZE];

#define row first
#define col second

#define IN_AREA(row,col)    (IN_RANGE(1,(row),N)&&IN_RANGE(1,(col),M))

#define EMPTY       0
#define PILLAR      1
#define CHAIR       2
#define MANNEQUIN   3
#define SIRU        4

typedef pair<int,int>   Pos;    // first:row,second:col

int     find_chair(int row,int col)
{
    queue<Pos>  q;

    visited[row][col] = true;
    q.push(make_pair(row,col));

    for(int step=0;!q.empty();step++)
    {
        for(int i=1,size=q.size();i<=size;i++,q.pop())
        {
            int current_row = q.front().row;
            int current_col = q.front().col;
            
            if( grid[current_row][current_col] == CHAIR )
            {
                return  step;
            }

            for(int d=0;d<MAX_DIR;d++)
            {
                int adj_row = current_row+adj[d].d_row;
                int adj_col = current_col+adj[d].d_col;

                if( !IN_AREA(adj_row,adj_col) || grid[adj_row][adj_col]==PILLAR )
                {
                    continue;
                } 
                
                if( scared[adj_row][adj_col]>NONE || visited[adj_row][adj_col]==true )
                {
                    continue;
                }

                visited[adj_row][adj_col] = true;
                q.push(make_pair(adj_row,adj_col));
            }
        }
    }

    return  -1;
}

Pos     input(queue<Pos>& mq)
{
    Pos start;

    cin>>N>>M>>K;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>grid[row][col];
            scared[row][col] = NONE;

            switch(grid[row][col])
            {
                case    MANNEQUIN:
                    scared[row][col] = K;
                    if( K !=0 ) mq.push(make_pair(row,col));
                    break;
                case    SIRU:
                    start = make_pair(row,col);
                    break;
                default:
                    // do nothing
                    break;
            }
        }
    }

    return  start;
}

void    mark_scared(queue<Pos>& mq)
{
    for(;!mq.empty();mq.pop())
    {
        int current_row = mq.front().row;
        int current_col = mq.front().col;
        int current_scared = scared[current_row][current_col];

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;
            int adj_scared = current_scared-1;

            if( !IN_AREA(adj_row,adj_col) ||
                    adj_scared<=scared[adj_row][adj_col] )
            {
                continue;
            }
            
            scared[adj_row][adj_col] = adj_scared;
            if( adj_scared > 0 ) mq.push(make_pair(adj_row,adj_col));
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<Pos>  mannequin_q;
    Pos         s = input(mannequin_q);

    mark_scared(mannequin_q);
    cout<<find_chair(s.row,s.col)<<'\n';

    return  0;
}