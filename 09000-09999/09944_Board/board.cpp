#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (30+1)
#define INF         0x7FFFFFFF
#define NONE        -1

#define UP          0
#define DOWN        1
#define LEFT        2
#define RIGHT       3
#define MAX_DIR     4

#define EMPTY   '.'
#define BLOCKED '*'

#define FALSE   0
#define TRUE    1

typedef pair<int,int>   Pos;

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

const int available_dir[MAX_DIR][2]
    ={{LEFT,RIGHT},{LEFT,RIGHT},{UP,DOWN},{UP,DOWN}};

int     N,M,min_moves,num_of_empty;
char    grid[MAX_SIZE][MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define IN_AREA(row,col,MAX_ROW,MAX_COL) \
    (IN_RANGE(1,(row),(MAX_ROW))&&IN_RANGE(1,(col),(MAX_COL)))

#define is_valid(row,col) \
    (IN_AREA((row),(col),N,M)&&grid[(row)][(col)]==EMPTY)

int input(vector<Pos>& e)
{
    if( scanf("%d %d",&N,&M) != 2 )
    {
        return  FALSE;
    }

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == EMPTY )
            {
                e.push_back(make_pair(row,col));
            }
        }
    }

    return  TRUE;
}

int dfs(int row,int col,int dir,
            int current_moves,int num_of_visited)
{
    if( num_of_visited == num_of_empty )
    {
        min_moves = min(min_moves,current_moves);
        return  0;
    }

    int adj_row = row+adj[dir].d_row;
    int adj_col = col+adj[dir].d_col;

    if( is_valid(adj_row,adj_col) )
    {
        grid[adj_row][adj_col] = BLOCKED;
        dfs(adj_row,adj_col,dir,
                current_moves,num_of_visited+1);
        grid[adj_row][adj_col] = EMPTY;
    }
    else
    {
        for(int i=0;i<2;i++)
        {
            int next_dir = available_dir[dir][i];

            adj_row = row+adj[next_dir].d_row;
            adj_col = col+adj[next_dir].d_col;

            if( is_valid(adj_row,adj_col) )
            {
                grid[adj_row][adj_col] = BLOCKED;
                dfs(adj_row,adj_col,next_dir,
                        current_moves+1,num_of_visited+1);
                grid[adj_row][adj_col] = EMPTY;
            }
        }
    }

    return  0;
}

int simulate(const vector<Pos>& e)
{
    if( e.size() == 1 )
    {
        return  0;
    }

    min_moves = INF;
    num_of_empty = e.size();

    for(int i=0;i<e.size();i++)
    {
        int row = e[i].first;
        int col = e[i].second;

        for(int d=0;d<MAX_DIR;d++)
        {
            grid[row][col] = BLOCKED;
            dfs(row,col,d,1,1);
            grid[row][col] = EMPTY;
        }
    }

    return  (min_moves==INF)?NONE:min_moves;
}

int main(void)
{
    for(int i=1;;i++)
    {
        vector<Pos> empty_pos;

        if( input(empty_pos) == FALSE )
        {
            break;
        }

        cout<<"Case "<<i<<": "<<
                simulate(empty_pos)<<'\n';
    }

    return  0;
}