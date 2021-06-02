#include    <iostream>

using namespace std;

#define MAX_SIZE    19
#define WIN_CNT     5

#define EMPTY   0
#define BLACK   1
#define WHITE   2

#define HORI    0
#define VERT    1
#define SLASH   2
#define BSLASH  3
#define MAX_DIR 4

const struct{int d_row,d_col;} adj[MAX_DIR] = {{0,1},{1,0},{-1,1},{1,1}};

typedef pair<int,int>   Pos;    // first:row, second:col

int     N,grid[MAX_SIZE+1][MAX_SIZE+1];
bool    checked[MAX_SIZE+1][MAX_SIZE+1][MAX_DIR];
Pos     p[MAX_SIZE*MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    init(void)
{
    for(int row=1;row<=MAX_SIZE;row++)
    {
        for(int col=1;col<=MAX_SIZE;col++)
        {
            checked[row][col][HORI] = checked[row][col][VERT] = 
                checked[row][col][SLASH] = checked[row][col][BSLASH] = false;
        }
    }
}

int     count_consecutive_stone(int s_row,int s_col,int dir)
{
    int ret,row,col;

    for(ret=0,row=s_row,col=s_col;;)
    {
        if( !IN_RANGE(1,row,MAX_SIZE) || !IN_RANGE(1,col,MAX_SIZE)
            || grid[row][col] != grid[s_row][s_col] )
        {
            break;
        }

        ret++;
        checked[row][col][dir] = true;

        row = row+adj[dir].d_row;
        col = col+adj[dir].d_col;
    }

    return  ret;
}

bool    check_game(int color)
{
    for(int row=1;row<=MAX_SIZE;row++)
    {
        for(int col=1;col<=MAX_SIZE;col++)
        {
            if( grid[row][col] != color )
            {
                continue;
            }

            for(int d=HORI;d<=BSLASH;d++)
            {
                if( checked[row][col][d] == true )
                {
                    continue;
                }

                if( count_consecutive_stone(row,col,d) == WIN_CNT )
                {
                    return  true;
                }
            }
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>p[i].first>>p[i].second;
    }

    for(int i=1,c=BLACK;i<=N;i++,c=(c==BLACK)?WHITE:BLACK)
    {
        int&    row = p[i].first;
        int&    col = p[i].second;

        init();
        grid[row][col] = c;

        if( check_game(c) == true )
        {
            cout<<i<<'\n';
            return  0;
        }
    }

    cout<<"-1\n";
    return  0;
}