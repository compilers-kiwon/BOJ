#include    <iostream>

using namespace std;

#define MAX_SIZE    (31+1)

static int  N,M,arr[MAX_SIZE][MAX_SIZE];

#define DOWN    0
#define RIGHT   1
#define MAX_DIR 2

const static struct{int d_row,d_col;} adj[MAX_DIR] = {{1,0},{0,1}};

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>arr[row][col];
        }
    }

    return  0;
}

bool    is_changed_well(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            if( arr[row][col] != M )
            {
                return  false;
            }
        }
    }

    return  true;
}

int turn_light(int row,int col,int d,int state)
{
    for(int offset=0;offset<N;offset++)
    {
        int cur_row = row+adj[d].d_row*offset;
        int cur_col = col+adj[d].d_col*offset;

        arr[cur_row][cur_col] = state;
    }

    return  0;
}

int turn_light_in_row(int col)
{
    int num_of_same_lights = 0;

    for(int row=1;row<=N;row++)
    {
        num_of_same_lights += (arr[row][col]==M)?1:0;    
    }

    if( num_of_same_lights > N/2 )
    {
        turn_light(1,col,DOWN,M);
    }

    return  0;
}

int turn_light_in_col(int row)
{
    int num_of_same_lights = 0;

    for(int col=1;col<=N;col++)
    {
        num_of_same_lights += (arr[row][col]==M)?1:0;    
    }

    if( num_of_same_lights > N/2 )
    {
        turn_light(row,1,RIGHT,M);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int row=1;row<=N;row++) turn_light_in_col(row);
    for(int col=1;col<=N;col++) turn_light_in_row(col);

    for(int row=1;row<=N;row++) turn_light_in_col(row);
    for(int col=1;col<=N;col++) turn_light_in_row(col);

    cout<<(is_changed_well()?1:0)<<'\n';
    return  0;
}