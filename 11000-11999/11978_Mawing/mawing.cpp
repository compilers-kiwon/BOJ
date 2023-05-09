#include    <iostream>
#include    <map>

using namespace std;

#define INF     0x7FFFFFFF
#define NONE    -1

typedef pair<int,int>   Pos;

enum{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    MAX_DIR = 4
};

const static struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define get_dir(d)  ((d)=='N'?UP:(d)=='S'?DOWN:(d)=='E'?RIGHT:LEFT)

static map<Pos,int> visited;

#define is_visited(v,row,col) ((v).find({(row),(col)})!=(v).end())

int simulate(void)
{
    int N,current_row,current_col,ret,t;

    cin>>N;
    current_row = current_col = t = 0;

    ret = INF;
    visited[{current_row,current_col}] = t++;

    for(int i=1;i<=N;i++)
    {
        char    D;
        int     S;

        cin>>D>>S;

        for(int step=1;step<=S;step++,t++)
        {
            current_row += adj[get_dir(D)].d_row;
            current_col += adj[get_dir(D)].d_col;

            if( is_visited(visited,current_row,current_col) )
            {
                ret = min(ret,t-visited[{current_row,current_col}]);
            }
            
            visited[{current_row,current_col}] = t;
        }
    }

    return  (ret==INF)?NONE:ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cout<<simulate()<<'\n';

    return  0;
}