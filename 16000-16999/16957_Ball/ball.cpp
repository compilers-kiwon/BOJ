#include    <iostream>

using namespace std;

#define MAX_SIZE            (500+1)
#define MAX_NUM             300000
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int,int>   Pos;    // first:row,second:col

int R,C,grid[MAX_SIZE][MAX_SIZE];
int num_of_balls[MAX_SIZE][MAX_SIZE],parent[MAX_NUM+1];
Pos num_pos[MAX_NUM+1];

int find_parent(int me)
{
    int&    ret = parent[me];

    if( ret != me )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

void    input(void)
{
    cin>>R>>C;

    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            cin>>grid[row][col];
            num_pos[grid[row][col]] = make_pair(row,col);
        }
    }
}

void    get_parent(void)
{
    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            int current_num = grid[row][col];
            int min_num = current_num;

            for(int d_row=-1;d_row<=1;d_row++)
            {
                for(int d_col=-1;d_col<=1;d_col++)
                {
                    int adj_row = row+d_row;
                    int adj_col = col+d_col;

                    if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
                    {
                        continue;
                    }

                    min_num = min(min_num,grid[adj_row][adj_col]);
                }
            }

            parent[current_num] = min_num;
        }
    }
}

void    simulate(void)
{
    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            int p = find_parent(grid[row][col]);
            int r = num_pos[p].first;
            int c = num_pos[p].second;

            num_of_balls[r][c]++;
        }
    }
}

void    print(void)
{
    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            cout<<num_of_balls[row][col]<<' ';
        }
        cout<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_parent();

    simulate();
    print();

    return  0;
}