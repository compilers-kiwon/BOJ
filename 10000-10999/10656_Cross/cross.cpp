#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (50+1)
#define MIN_LEN     3

enum{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    MAX_DIR = 4
};

static int  N,M;
static char grid[MAX_SIZE][MAX_SIZE+1];

#define TRUE    1
#define FALSE   0

#define BLOCKED '#'
#define EMPTY   '.'

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define IN_AREA(row,max_row,col,max_col) \
    (IN_RANGE(1,(row),(max_row))&&IN_RANGE(1,(col),(max_col)))

typedef pair<int,int>   Pos;
typedef pair<int,int>   Offset;

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int is_blocked(int row,int col,Offset s)
{
    int adj_row = row+adj[s.first].d_row*s.second;
    int adj_col = col+adj[s.first].d_col*s.second;

    if( !IN_AREA(adj_row,N,adj_col,M)
            || grid[adj_row][adj_col] == BLOCKED )
    {
        return  TRUE;
    }

    return  FALSE;
}

int is_available(int row,int col,Offset s)
{
    int adj_row = row+adj[s.first].d_row*s.second;
    int adj_col = col+adj[s.first].d_col*s.second;

    if( IN_AREA(adj_row,N,adj_col,M)
            && grid[adj_row][adj_col] == EMPTY )
    {
        return  TRUE;
    }

    return  FALSE;
}

int is_head(int row,int col)
{
    Offset  row_offset[MIN_LEN] = {{UP,1},{DOWN,1},{DOWN,2}};
    Offset  col_offset[MIN_LEN] = {{LEFT,1},{RIGHT,1},{RIGHT,2}};

    if( is_blocked(row,col,row_offset[0])
        && is_available(row,col,row_offset[1])
        && is_available(row,col,row_offset[2]) )
    {
        return  TRUE;
    }

    if( is_blocked(row,col,col_offset[0])
        && is_available(row,col,col_offset[1])
        && is_available(row,col,col_offset[2]) )
    {
        return  TRUE;
    }

    return  FALSE;
}

int get_head(vector<Pos>& heads)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == EMPTY
                    && is_head(row,col) == TRUE )
            {
                heads.push_back({row,col});
            }
        }
    }

    return  0;
}

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> answer;

    input();
    get_head(answer);

    cout<<answer.size()<<'\n';

    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i].first<<' '<<answer[i].second<<'\n';
    }

    return  0;
}