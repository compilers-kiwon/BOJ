#include    <iostream>

using namespace std;

#define SCALER      3
#define MAX_SIZE    300

static int  N,M,attr[MAX_SIZE][MAX_SIZE];
static char grid[SCALER*MAX_SIZE][SCALER*MAX_SIZE+1];

#define UP      0
#define LEFT    1
#define DOWN    2
#define RIGHT   3
#define MAX_DIR 4

#define get_faced_dir(d)    (((d)+2)%MAX_DIR)
#define get_mid(p)          ((p)*SCALER+1)
#define is_empty(row,col)   (grid[(row)][(col)]=='.')
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{0,-1},{1,0},{0,1}};

#define write_attr(d)           (1<<(d))
#define read_attr(row,col,d)    (attr[(row)][(col)]&(1<<(d)))

int get_box_char(int row,int col)
{
    int ret = 0;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !is_empty(adj_row,adj_col) )
        {
            ret |= write_attr(d);
        }
    }

    return  ret;
}

int get_attr(void)
{
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<M;col++)
        {
            int mid_row = get_mid(row);
            int mid_col = get_mid(col);

            if( is_empty(mid_row,mid_col) )
            {
                continue;
            }

            attr[row][col] = get_box_char(mid_row,mid_col);
        }
    }

    return  0;
}

int restore(void)
{
    for(int current_box_row=0;current_box_row<N;current_box_row++)
    {
        for(int current_box_col=0;current_box_col<M;current_box_col++)
        {
            int current_mid_row = get_mid(current_box_row);
            int current_mid_col = get_mid(current_box_col);

            if( is_empty(current_mid_row,current_mid_col) )
            {
                continue;
            }

            for(int d=0;d<MAX_DIR;d++)
            {
                if( (attr[current_box_row][current_box_col]&(1<<d)) == 0 )
                {
                    continue;
                }

                int adj_box_row = current_box_row+adj[d].d_row;
                int adj_box_col = current_box_col+adj[d].d_col;

                if( !IN_RANGE(0,adj_box_row,N-1)
                        || !IN_RANGE(0,adj_box_col,M-1) )
                {
                    continue;
                }

                int adj_mid_row = get_mid(adj_box_row);
                int adj_mid_col = get_mid(adj_box_col);

                if( !is_empty(adj_mid_row,adj_mid_col) )
                {
                    continue;
                }

                attr[adj_box_row][adj_box_col] |= 
                            write_attr(get_faced_dir(d));
            }
        }
    }

    for(int box_row=0;box_row<N;box_row++)
    {
        for(int box_col=0;box_col<M;box_col++)
        {
            int mid_row = get_mid(box_row);
            int mid_col = get_mid(box_col);

            if( !is_empty(mid_row,mid_col) )
            {
                continue;
            }
            
            grid[mid_row][mid_col] = '#';

            for(int d=0;d<MAX_DIR;d++)
            {
                if( read_attr(box_row,box_col,d) == 0 )
                {
                    continue;
                }
                
                int row = mid_row+adj[d].d_row;
                int col = mid_col+adj[d].d_col;
                
                grid[row][col] = '#';
            }
        }
    }

    return  0;
}

int print(void)
{
    for(int row=0;row<SCALER*N;row++)
    {
        cout<<&grid[row][0]<<'\n';
    }

    return  0;
}

int input(void)
{
    cin>>N>>M;

    for(int row=0;row<SCALER*N;row++)
    {
        cin>>&grid[row][0];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_attr();

    restore();
    print();

    return  0;
}