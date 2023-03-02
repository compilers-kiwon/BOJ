#include    <iostream>
#include    <vector>

using namespace std;

#define TRUE    1
#define FALSE   0

#define MAX_SIZE    (15+1)
#define MAX_DIR     4

typedef pair<int,int>   Pos;

static int  N,M;
static char grid[MAX_SIZE][MAX_SIZE+1];

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int fill_cross(const vector<Pos>& p,char c)
{
    for(int i=0;i<p.size();i++)
    {
        grid[p[i].first][p[i].second] = c;
    }

    return  0;
}

#define MARK_CROSS(p)       (fill_cross((p),'*'))
#define RESTORE_CROSS(p)    (fill_cross((p),'#'))

int draw_cross(int row,int col,
                int length,vector<Pos>& cross)
{
    int ret = TRUE;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row*length;
        int adj_col = col+adj[d].d_col*length;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
        {
            ret = FALSE;
            break;
        }

        if( grid[adj_row][adj_col] != '#' )
        {
            ret = FALSE;
            break;
        }

        cross.push_back(make_pair(adj_row,adj_col));
    }

    return  ret;
}

int find_max_cross(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            for(int offset=0,area=1;;offset++,area+=4)
            {
                vector<Pos> dummy;

                if( draw_cross(row,col,offset,dummy) == FALSE )
                {
                    break;
                }

                ret = max(ret,area);
            }
        }
    }
    
    return  ret;
}

int simulate(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            vector<Pos> cross;

            for(int offset=0,area=1;;offset++,area+=4)
            {
                if( draw_cross(row,col,offset,cross) == FALSE )
                {
                    RESTORE_CROSS(cross);
                    break;
                }

                MARK_CROSS(cross);
                ret = max(ret,area*find_max_cross());
            }
        }
    }

    return  ret;
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

    input();
    cout<<simulate()<<'\n';

    return  0;
}