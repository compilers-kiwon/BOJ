#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (1000+1)

#define TRUE    1
#define FALSE   0

enum{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    MAX_DIR = 4
};

static int  M,N;
static char grid[MAX_SIZE][MAX_SIZE+1];
static bool occupied[MAX_SIZE][MAX_SIZE][MAX_DIR];

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

const int empty_cell[MAX_DIR] = {RIGHT,RIGHT,DOWN,DOWN};

#define get_adj_row(row,dir)    ((row)+adj[(dir)].d_row)
#define get_adj_col(col,dir)    ((col)+adj[(dir)].d_col)

#define is_empty(row,col)       (grid[(row)][(col)]=='.')

#define is_wall(row,col,dir) \
    (grid[get_adj_row((row),(dir))][get_adj_col((col),(dir))]=='X')

typedef pair<int,int>   Pos;

int can_be_displayed(int current_row,int current_col,int display_dir)
{
    int adj_row = get_adj_row(current_row,empty_cell[display_dir]);
    int adj_col = get_adj_col(current_col,empty_cell[display_dir]);

    if( !is_empty(adj_row,adj_col) )
    {
        return  FALSE;
    }

    if( !is_wall(current_row,current_col,display_dir)
                || !is_wall(adj_row,adj_col,display_dir) )
    {
        return  FALSE;
    }

    if( occupied[current_row][current_col][display_dir]
                || occupied[adj_row][adj_col][display_dir] )
    {
        return  FALSE;
    }

    occupied[current_row][current_col][display_dir]
            = occupied[adj_row][adj_col][display_dir] = true;
    
    return  TRUE;
}

int input(vector<Pos>& p)
{
    cin>>M>>N;

    for(int row=1;row<=M;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=N;col++)
        {
            if( is_empty(row,col) )
            {
                p.push_back({row,col});
            }
        }
    }

    return  0;
}

int simulate(const vector<Pos>& p)
{
    int ret = 0;

    for(int i=0;i<p.size();i++)
    {
        int row = p[i].first;
        int col = p[i].second;

        for(int d=UP;d<=RIGHT;d++)
        {
            if( can_be_displayed(row,col,d) == TRUE )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> empty_cells;

    input(empty_cells);
    cout<<simulate(empty_cells)<<'\n';

    return  0;
}