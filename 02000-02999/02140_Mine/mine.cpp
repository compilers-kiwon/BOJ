#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100+1)
#define INF         0x7FFFFFFF

#define UNKNOWN '#'
#define MINE    '*'
#define EMPTY   ' '

static int  N;
static char grid[MAX_SIZE][MAX_SIZE+1];

typedef pair<int,int>   Pos;

#define char2int(c) ((int)((c)-'0'))

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define is_number(c)        IN_RANGE('0',(c),'9')

int get_min_num(int row,int col,vector<Pos>& p)
{
    int ret = INF;

    for(int d_row=-1;d_row<=1;d_row++)
    {
        for(int d_col=-1;d_col<=1;d_col++)
        {
            int adj_row = row+d_row;
            int adj_col = col+d_col;

            if( is_number(grid[adj_row][adj_col]) )
            {
                p.push_back(make_pair(adj_row,adj_col));
                ret = min(ret,char2int(grid[adj_row][adj_col]));
            }
        }
    }

    return  ret;
}

int decrease_numbers(const vector<Pos>& p)
{
    for(int i=0;i<p.size();i++)
    {
        int row = p[i].first;
        int col = p[i].second;

        grid[row][col]--;
    }

    return  0;
}

int open_unknown_cell(int row,int col)
{
    if( grid[row][col] != UNKNOWN )
    {
        return  0;
    }

    vector<Pos> adj_num;

    if( get_min_num(row,col,adj_num) == 0 )
    {
        grid[row][col] = EMPTY;
    }
    else
    {
        grid[row][col] = MINE;
        decrease_numbers(adj_num);
    }

    return  0;
}

int determine_mine_pos(void)
{
    for(int row=2,col=2;col<=N-1;col++)
    {
        open_unknown_cell(row,col);
    }

    for(int row=3,left_col=2,right_col=N-1;row<=N-2;row++)
    {
        open_unknown_cell(row,left_col);
        open_unknown_cell(row,right_col);
    }

    for(int row=N-1,col=2;col<=N-1;col++)
    {
        open_unknown_cell(row,col);
    }

    return  0;
}

int get_max_num_of_mines(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            char    c = grid[row][col];

            if( c==UNKNOWN || c==MINE )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int input(void)
{
    cin>>N;

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

    input();
    determine_mine_pos();

    cout<<get_max_num_of_mines()<<'\n';

    return  0;
}