#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_DIR     4
#define NONE        -1

#define VISIBLE     '.'
#define INVISIBLE   '#'

typedef pair<int,int>   Pos;    // first:row,second:col

int     R,C;
Pos     H;
bool    ward[MAX_SIZE][MAX_SIZE];
char    grid[MAX_SIZE][MAX_SIZE+1];
string  path;

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define visit(r,c,q,v)      {(v)[(r)][(c)]=true;(q).push(make_pair((r),(c)));}

void    install_ward(int row,int col)
{
    if( ward[row][col] == true )
    {
        return;
    }

    queue<Pos>  q;

    visit(row,col,q,ward);

    for(char c=grid[row][col];!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) ||
                    grid[adj_row][adj_col]!=c || ward[adj_row][adj_col]!=false )
            {
                continue;
            }

            visit(adj_row,adj_col,q,ward);
        }
    }
}

void    simulate(void)
{
    int row = H.first;
    int col = H.second;

    for(int i=0;i<path.length();i++)
    {
        int d = NONE;

        switch(path[i])
        {
            case    'U':
                d=0;break;
            case    'D':
                d=1;break;
            case    'L':
                d=2;break;
            case    'R':
                d=3;break;
            case    'W':
                install_ward(row,col);
                break;
            default:
                // do nothing
                break;
        }

        if( d != NONE )
        {
            row = row+adj[d].d_row;
            col = col+adj[d].d_col;
        }
    }

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( IN_RANGE(1,adj_row,R) && IN_RANGE(1,adj_col,C) )
        {
            grid[adj_row][adj_col] = VISIBLE;
        }
    }

    grid[row][col] = VISIBLE;

    for(row=1;row<=R;row++)
    {
        for(col=1;col<=C;col++)
        {
            if( ward[row][col] == true )
            {
                grid[row][col] = VISIBLE;
            }
        }
    }
}

void    print_grid(void)
{
    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            cout<<((grid[row][col]==VISIBLE)?
                                VISIBLE:INVISIBLE);
        }
        cout<<'\n';
    }
}

void    input(void)
{
    cin>>R>>C;

    for(int row=1;row<=R;row++)
    {
        cin>>&grid[row][1];
    }

    cin>>H.first>>H.second>>path;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print_grid();

    return  0;
}