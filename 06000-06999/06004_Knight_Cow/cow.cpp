#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (150+1)
#define NONE        -1
#define MAX_DIR     8

#define KNIGHT      'K'
#define HAYBALE     'H'
#define OBSTACLE    '*'

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int,int>   Pos;    // first:row,second:col

const struct{int d_row,d_col;} adj[MAX_DIR] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

int     X,Y,visited[MAX_SIZE][MAX_SIZE];
char    pasture[MAX_SIZE][MAX_SIZE+1];
Pos     s;

void    input(void)
{
    cin>>X>>Y;

    for(int row=1;row<=Y;row++)
    {
        cin>>&pasture[row][1];

        for(int col=1;col<=X;col++)
        {
            if( pasture[row][col] == KNIGHT )
            {
                s = make_pair(row,col);
            }

            visited[row][col] = NONE;
        }
    }
}

int     move(void)
{
    int         ret;
    queue<Pos>  q;

    q.push(s);
    visited[s.first][s.second] = 0;

    for(;!q.empty();q.pop())
    {
        int current_row, current_col;

        current_row = q.front().first;
        current_col = q.front().second;

        if( pasture[current_row][current_col] == HAYBALE )
        {
            ret = visited[current_row][current_col];
            break;
        }

        for(int i=0;i<MAX_DIR;i++)
        {
            int adj_row,adj_col;

            adj_row = current_row+adj[i].d_row;
            adj_col = current_col+adj[i].d_col;

            if( !IN_RANGE(1,adj_row,Y) || !IN_RANGE(1,adj_col,X) )
            {
                continue;
            }

            if( pasture[adj_row][adj_col]==OBSTACLE || visited[adj_row][adj_col]!=NONE )
            {
                continue;
            }

            q.push(make_pair(adj_row,adj_col));
            visited[adj_row][adj_col] = visited[current_row][current_col]+1;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<move()<<'\n';

    return  0;
}