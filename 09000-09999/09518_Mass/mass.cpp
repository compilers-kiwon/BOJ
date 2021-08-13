#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (50+1)

#define PERSON  'o'
#define EMPTY   '.'

#define MAX_DIR 4

typedef pair<int,int>   Pos;    // first:row,second:col
const struct{int d_row,d_col;}  adj[MAX_DIR] = {{0,1},{1,1},{1,0},{1,-1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int     R,S,cnt;
char    grid[MAX_SIZE][MAX_SIZE+1];

void    input(void)
{
    cin>>R>>S;

    for(int row=1;row<=R;row++)
    {
        cin>>&grid[row][1];
    }
}

int     get_init_adj_person(int row,int col)
{
    int ret = 0;

    for(int i=0;i<MAX_DIR;i++)
    {
        int adj_row = row+adj[i].d_row;
        int adj_col = col+adj[i].d_col;

        if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,S) )
        {
            continue;
        }

        if( grid[adj_row][adj_col] == PERSON )
        {
            ret++;
        }
    }

    return  ret;
}

void    get_init_cnt(vector<Pos>& empty_seat)
{
    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=S;col++)
        {
            if( grid[row][col] == PERSON )
            {
                cnt += get_init_adj_person(row,col);
            }
            else
            {
                empty_seat.push_back(make_pair(row,col));
            }
        }
    }
}

int     get_num_of_max_handshake(vector<Pos>& empty_seat)
{
    int ret = 0;

    for(int i=0;i<empty_seat.size();i++)
    {
        int&    row = empty_seat[i].first;
        int&    col = empty_seat[i].second;
        int     num_of_adj_persons = 0;

        for(int d_row=-1;d_row<=1;d_row++)
        {
            for(int d_col=-1;d_col<=1;d_col++)
            {
                int adj_row = row+d_row;
                int adj_col = col+d_col;

                if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,S) )
                {
                    continue;
                }

                if( grid[adj_row][adj_col] == PERSON )
                {
                    num_of_adj_persons++;
                }
            }
        }

        ret = max(ret,num_of_adj_persons);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> empty;

    input();
    get_init_cnt(empty);

    cout<<cnt+get_num_of_max_handshake(empty)<<'\n';

    return  0;
}