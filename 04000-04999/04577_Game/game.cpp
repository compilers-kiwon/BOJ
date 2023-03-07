#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_SIZE    (15+1)

typedef pair<int,int>   Pos;    // first:row,second:col

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define TRUE    1
#define FALSE   0

#define get_dir(c)  ((c)=='U'?UP:(c)=='D'?DOWN:(c)=='L'?LEFT:RIGHT)

#define COMPLETE    1
#define INCOMPLETE  0

#define is_empty(r,c,g) ((g)[(r)][(c)]=='+'||(g)[(r)][(c)]=='.')
#define is_box(r,c,g)   ((g)[(r)][(c)]=='B'||(g)[(r)][(c)]=='b')

int input(int& row_size,int& col_size,string& move,
            vector<Pos>& target_pos,Pos& p,char grid[][MAX_SIZE+1])
{
    cin>>row_size>>col_size;

    if( row_size==0 && col_size==0 )
    {
        return  FALSE;
    }

    for(int row=1;row<=row_size;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=col_size;col++)
        {
            switch(grid[row][col])
            {
                case    'W':
                    target_pos.push_back(make_pair(row,col));
                case    'w':
                    p = make_pair(row,col);
                    break;
                case    '+':
                case    'B':
                    target_pos.push_back(make_pair(row,col));
                    break;
                default:
                    // do nothing
                    break;
            }
        }
    }

    cin>>move;

    return  TRUE;
}

int is_completed(vector<Pos>& target_pos,
                    char grid[][MAX_SIZE+1])
{
    for(int i=0;i<target_pos.size();i++)
    {
        int&    row = target_pos[i].first;
        int&    col = target_pos[i].second;

        if( grid[row][col] != 'B' )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int move_to_empty(Pos player,Pos empty,
                    char grid[][MAX_SIZE+1])
{
    int player_row = player.first;
    int player_col = player.second;

    int empty_row = empty.first;
    int empty_col = empty.second;

    grid[player_row][player_col] = 
        (grid[player_row][player_col]=='W')?'+':'.';
    grid[empty_row][empty_col] = 
        (grid[empty_row][empty_col]=='+')?'W':'w';
    
    return  0;
}

int move_box(Pos box_pos,int dir,
                char grid[][MAX_SIZE+1])
{
    int box_row = box_pos.first;
    int box_col = box_pos.second;

    int adj_row = box_row+adj[dir].d_row;
    int adj_col = box_col+adj[dir].d_col;

    if( !is_empty(adj_row,adj_col,grid) )
    {
        return  FALSE;
    }

    grid[box_row][box_col] = 
        (grid[box_row][box_col]=='B')?'+':'.';
    grid[adj_row][adj_col] = 
        (grid[adj_row][adj_col]=='+')?'B':'b';

    return  TRUE;
}

int simulate(Pos& p,vector<Pos>& target_pos,
                const string& move,char grid[][MAX_SIZE+1])
{
    int row = p.first;
    int col = p.second;

    for(int i=0;i<move.size();i++)
    {
        int d = get_dir(move[i]);
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( grid[adj_row][adj_col] == '#' )
        {
            continue;
        }

        if( is_empty(adj_row,adj_col,grid) )
        {
            move_to_empty({row,col},{adj_row,adj_col},grid);
            row = adj_row,col=adj_col;

            continue;
        }

        if( is_box(adj_row,adj_col,grid) &&
                move_box({adj_row,adj_col},d,grid) )
        {

            move_to_empty({row,col},{adj_row,adj_col},grid);
            row = adj_row,col=adj_col;
        }

        if( is_completed(target_pos,grid) == TRUE )
        {
            return  COMPLETE;
        }
    } 

    return  INCOMPLETE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;;i++)
    {
        int     R,C;
        Pos     p;
        string  move;
        char    grid[MAX_SIZE][MAX_SIZE+1];
        vector<Pos> target_pos;

        if( input(R,C,move,target_pos,p,grid) == FALSE )
        {
            break;
        }

        if( simulate(p,target_pos,move,grid) == INCOMPLETE )
        {
            cout<<"Game "<<i<<": incomplete\n";
        }
        else
        {
            cout<<"Game "<<i<<": complete\n";
        }

        for(int row=1;row<=R;row++)
        {
            cout<<&grid[row][1]<<'\n';
        }
    }

    return  0;
}