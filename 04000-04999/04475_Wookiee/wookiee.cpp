#include    <iostream>
#include    <string>

using namespace std;

#define GRID_SIZE   5
#define MAX_DIR     4
#define NUM_TO_WIN  4

static char grid[GRID_SIZE+1][GRID_SIZE+2];

const static struct{int d_row,d_col;} adj[MAX_DIR][2] = {
    {{-1,0},{1,0}},{{0,-1},{0,1}},{{-1,-1},{1,1}},{{-1,1},{1,-1}}
};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

bool    input(void)
{
    string  str;

    cin>>str;
    if(str=="Finished") return false;

    for(int i=2;i<=GRID_SIZE*GRID_SIZE;i++)
    {
        char    c;

        cin>>c;
        str.push_back(c);
    }

    for(int i=0,row=1,col=1;i<str.length();i++,col++)
    {
        if(col>GRID_SIZE) row++,col=1;
        grid[row][col] = str[i];
    }

    return  true;
}

bool    win(int row,int col,char p)
{
    for(int d=0;d<MAX_DIR;d++)
    {
        int cnt = 1;

        for(int i=0;i<2;i++)
        {
            for(int offset=1;;offset++,cnt++)
            {
                int adj_row = row+adj[d][i].d_row*offset;
                int adj_col = col+adj[d][i].d_col*offset;

                if( !IN_RANGE(1,adj_row,GRID_SIZE)
                        || !IN_RANGE(1,adj_col,GRID_SIZE) )
                {
                    break;
                }

                if( grid[adj_row][adj_col] != p )
                {
                    break;
                }
            }
        }

        if( cnt >= NUM_TO_WIN )
        {
            return  true;
        }
    }

    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int     num = 1;
        bool    found = false;

        if( input() == false )
        {
            break;
        }

        for(int row=1;row<=GRID_SIZE;row++)
        {
            for(int col=1;col<=GRID_SIZE;col++,num++)
            {
                if( grid[row][col] != '*' )
                {
                    continue;
                }

                if( !win(row,col,'O') && !win(row,col,'X') )
                {
                    cout<<num<<'\n';
                    found = true;
                    break;
                }
            }

            if( found == true )
            {
                break;
            }
        }
    }

    return  0;
}