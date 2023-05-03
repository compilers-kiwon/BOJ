#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (2000+1)
#define MAX_DIR     4

typedef pair<int,int>   Pos;

static int  N;
static char grid[MAX_SIZE][MAX_SIZE+1];
static bool bomb[MAX_SIZE][MAX_SIZE];

static vector<Pos>  buildings;

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define IN_AREA(r,c,s)      (IN_RANGE(1,(r),(s))&&IN_RANGE(1,(c),(s)))

#define is_empty(r,c)       (grid[(r)][(c)]=='.')
#define is_building(r,c)    (grid[(r)][(c)]=='O')

int input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=N;col++)
        {
            if( is_building(row,col) )
            {
                buildings.push_back({row,col});
            }

            bomb[row][col] = true;
        }
    }

    return  0;
}

int remove_bomb(int row,int col,int dir)
{
    for(int adj_row,adj_col;;row=adj_row,col=adj_col)
    {
        adj_row = row+adj[dir].d_row;
        adj_col = col+adj[dir].d_col;

        if( !IN_AREA(adj_row,adj_col,N)
                || !is_empty(adj_row,adj_col) )
        {
            break;
        }

        bomb[adj_row][adj_col] = false;
    }

    return  0;
}

int simulate(void)
{
    for(int i=0;i<buildings.size();i++)
    {
        for(int dir=0;dir<MAX_DIR;dir++)
        {
            int&    row = buildings[i].first;
            int&    col = buildings[i].second;

            remove_bomb(row,col,dir);
        }
    }

    return  0;
}

int print(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cout<<(!is_empty(row,col)?
                    grid[row][col]:(bomb[row][col])?'B':'.');
        }

        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return  0;
}