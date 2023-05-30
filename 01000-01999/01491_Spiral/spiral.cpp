#include    <iostream>

using namespace std;

#define MAX_SIZE    5000
#define MAX_DIR     4
#define NONE        -1

const static struct{int d_row,d_col;}
    adj[MAX_DIR] = {{0,1},{-1,0},{0,-1},{1,0}};

static int  N,M;    // N:width,M:height
static bool v[MAX_SIZE][MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int turn_dir(int cur_dir,int cur_row,int cur_col)
{
    int ret = NONE;

    for(int d=1;d<MAX_DIR;d++)
    {
        int adj_dir = (cur_dir+d)%MAX_DIR;
        int adj_row = cur_row+adj[adj_dir].d_row;
        int adj_col = cur_col+adj[adj_dir].d_col;

        if( IN_RANGE(0,adj_row,M-1)
            && IN_RANGE(0,adj_col,N-1)
            && v[adj_row][adj_col] == false )
        {
            ret = adj_dir;
            break;
        }
    }

    return  ret;
}

int simulate(void)
{
    int cur_row,cur_col,cur_dir;

    cur_row = cur_col = cur_dir = 0;
    v[cur_row][cur_col] = true;

    for(;;)
    {
        int adj_row = cur_row+adj[cur_dir].d_row;
        int adj_col = cur_col+adj[cur_dir].d_col;

        if( IN_RANGE(0,adj_row,M-1)
            && IN_RANGE(0,adj_col,N-1)
            && v[adj_row][adj_col] == false )
        {
            cur_row = adj_row;
            cur_col = adj_col;
            v[cur_row][cur_col] = true;
        }
        else
        {
            if( (cur_dir=turn_dir(cur_dir,cur_row,cur_col)) == NONE )
            {
                cout<<cur_col<<' '<<cur_row<<'\n';
                break;
            }
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    simulate();

    return  0;
}