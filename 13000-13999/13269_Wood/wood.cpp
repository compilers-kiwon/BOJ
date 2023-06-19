#include    <iostream>

using namespace std;

#define MAX_SIZE    (500+1)

#define NONE    0
#define INF     0x7FFFFFFF

static int  N,M,expected[MAX_SIZE][MAX_SIZE];
static int  top_view[MAX_SIZE][MAX_SIZE];
static int  front_view[MAX_SIZE],side_view[MAX_SIZE];

#define TRUE    1
#define FALSE   0

int simulate_front(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( top_view[row][col]!=NONE &&
                    front_view[col]<expected[row][col] )
            {
                expected[row][col] = front_view[col];
            }
        }
    }

    return  0;
}

int simulate_side(void)
{
    for(int col=1;col<=M;col++)
    {
        for(int row=1;row<=N;row++)
        {
            if( top_view[row][col]!=NONE &&
                    side_view[row]<expected[row][col] )
            {
                expected[row][col] = side_view[row];
            }
        }
    }

    return  0;
}

int verify_front(void)
{
    for(int col=1;col<=M;col++)
    {
        int max_num = 0;

        for(int row=1;row<=N;row++)
        {
            max_num = max(max_num,expected[row][col]);
        }

        if( max_num != front_view[col] )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int verify_side(void)
{
    for(int row=1;row<=N;row++)
    {
        int max_num = 0;

        for(int col=1;col<=M;col++)
        {
            max_num = max(max_num,expected[row][col]);
        }

        if( max_num != side_view[row] )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>top_view[row][col];
            expected[row][col] =
                (top_view[row][col])?INF:NONE;
        }
    }

    for(int col=1;col<=M;col++)
    {
        cin>>front_view[col];
    }

    for(int row=N;row>=1;row--)
    {
        cin>>side_view[row];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    simulate_front();
    simulate_side();

    if( verify_front() && verify_side() )
    {
        for(int row=1;row<=N;row++)
        {
            for(int col=1;col<=M;col++)
            {
                cout<<expected[row][col]<<(col==M?'\n':' ');
            }
        }
    }
    else
    {
        cout<<"-1\n";
    }

    return  0;
}