#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

#define UP          0
#define DOWN        1
#define LEFT        2
#define RIGHT       3
#define MAX_DIR     4

static int  N,M,R;
static int  grid[MAX_SIZE][MAX_SIZE];
static char state[MAX_SIZE][MAX_SIZE];

#define AVAILABLE   'S'
#define UNAVAILABLE 'F'

#define get_dir(d)  ((d)=='N'?UP:(d)=='S'?DOWN:(d)=='W'?LEFT:RIGHT)

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define IN_GRID(row,col,row_size,col_size) \
    (IN_RANGE(1,(row),(row_size))&&IN_RANGE(1,(col),(col_size)))

#define reach_end_pos(cur_row,cur_col,end_row,end_col) \
                ((cur_row)==(end_row)&&(cur_col)==(end_col))

int init(void)
{
    cin>>N>>M>>R;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>grid[row][col];
            state[row][col] = AVAILABLE;
        }
    }

    return  0;
}

int update_end_pos(int cur_row,int cur_col,
                    int& end_row,int& end_col,int dir)
{
    end_row = cur_row+adj[dir].d_row*grid[cur_row][cur_col];
    end_col = cur_col+adj[dir].d_col*grid[cur_row][cur_col];

    return  0;
}

int collapse(int row,int col,int dir)
{
    if( state[row][col] == UNAVAILABLE )
    {
        return  0;
    }

    int ret,end_row,end_col; 

    ret = 0;
    update_end_pos(row,col,end_row,end_col,dir);
    
    for(int length=grid[row][col];IN_GRID(row,col,N,M)
            &&!reach_end_pos(row,col,end_row,end_col);length--)
    {
        if( state[row][col] == AVAILABLE )
        {
            if( grid[row][col] > length )
            {
                length = grid[row][col];
                update_end_pos(row,col,end_row,end_col,dir);
            }

            ret++;
            state[row][col] = UNAVAILABLE;
        }

        row += adj[dir].d_row;
        col += adj[dir].d_col;
    }

    return  ret;
}

int restore(int row,int col)
{
    state[row][col] = AVAILABLE;
    return  0;
}

int print(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cout<<state[row][col]<<' ';
        }

        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int score = 0;

    init();

    for(int i=1;i<=R;i++)
    {
        int     row,col;
        char    dir;

        cin>>row>>col>>dir;
        score += collapse(row,col,get_dir(dir));

        cin>>row>>col;
        restore(row,col);
    }

    cout<<score<<'\n';
    print();

    return  0;
}