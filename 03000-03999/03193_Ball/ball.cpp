#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_DIR     4

#define BALL    'L'
#define EMPTY   '.'
#define BLOCK   'X'

typedef struct{int prev_row,next_row,prev_col,next_col;}    State;

int     N,K,ball_row,ball_col,r_state;
char    grid[MAX_SIZE+1][MAX_SIZE+1];
string  rotation;
State   s[MAX_SIZE][MAX_SIZE];

#define clockwise(d)        (((d)+1)%MAX_DIR)
#define counterclockwise(d) (((d)+(MAX_DIR-1))%MAX_DIR)

void    input(void)
{
    cin>>N>>K;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=N;col++)
        {
            if( grid[row][col] == BALL )
            {
                ball_row = row;
                ball_col = col;
                grid[row][col] = EMPTY;
            }
        }
    }

    for(int i=1;i<=K;i++)
    {
        char    c;

        cin>>c;
        rotation.push_back(c);
    }

    for(int i=1;i<=N;i++)
    {
        grid[i][0] = grid[i][N+1]
            = grid[0][i] = grid[N+1][i] = BLOCK;
    }
}

void    init(void)
{
    // prev_row
    for(int col=1;col<=N;col++)
    {
        int prev_block;

        for(int row=0;row<=N;row++)
        {
            switch(grid[row][col])
            {
                case    BLOCK:
                    prev_block = row;
                    break;
                case    EMPTY:
                    s[row][col].prev_row = prev_block+1;
                    break;
                default:
                    // do nothing;
                    break;
            }
        }
    }

    // next_row
    for(int col=1;col<=N;col++)
    {
        int next_block;

        for(int row=N+1;row>=1;row--)
        {
            switch(grid[row][col])
            {
                case    BLOCK:
                    next_block = row;
                    break;
                case    EMPTY:
                    s[row][col].next_row = next_block-1;
                    break;
                default:
                    // do nothing;
                    break;
            }
        }
    }

    // prev_col
    for(int row=1;row<=N;row++)
    {
        int prev_block;

        for(int col=0;col<=N;col++)
        {
            switch(grid[row][col])
            {
                case    BLOCK:
                    prev_block = col;
                    break;
                case    EMPTY:
                    s[row][col].prev_col = prev_block+1;
                    break;
                default:
                    // do nothing;
                    break;
            }
        }
    }

    // next_col
    for(int row=1;row<=N;row++)
    {
        int next_block;

        for(int col=N+1;col>=1;col--)
        {
            switch(grid[row][col])
            {
                case    BLOCK:
                    next_block = col;
                    break;
                case    EMPTY:
                    s[row][col].next_col = next_block-1;
                    break;
                default:
                    // do nothing;
                    break;
            }
        }
    }
}

void    print(void)
{
    switch(r_state)
    {
        case    0:
            for(int row=1;row<=N;row++)
            {
                for(int col=1;col<=N;col++)
                {
                    cout<<grid[row][col];
                }
                cout<<'\n';
            }
            break;
        case    1:
            for(int col=1;col<=N;col++)
            {
                for(int row=N;row>=1;row--)
                {
                    cout<<grid[row][col];
                }
                cout<<'\n';
            }
            break;
        case    2:
            for(int row=N;row>=1;row--)
            {
                for(int col=N;col>=1;col--)
                {
                    cout<<grid[row][col];
                }
                cout<<'\n';
            }
            break;
        case    3:
            for(int col=N;col>=1;col--)
            {
                for(int row=1;row<=N;row++)
                {
                    cout<<grid[row][col];
                }
                cout<<'\n';
            }
            break;
        default:
            //do nothing
            break;
    }
}

void    simulate(void)
{
    for(int i=0;i<K;i++)
    {
        if( rotation[i] == 'L' )
        {
            r_state = counterclockwise(r_state);
        }
        else
        {
            r_state = clockwise(r_state);
        }

        switch(r_state)
        {
            case    0:
                ball_row = s[ball_row][ball_col].next_row;
                break;
            case    1:
                ball_col = s[ball_row][ball_col].next_col;
                break;
            case    2:
                ball_row = s[ball_row][ball_col].prev_row;
                break;
            case    3:
                ball_col = s[ball_row][ball_col].prev_col;
                break;
            default:
                // do nothing
                break;
        }
    }

    grid[ball_row][ball_col] = BALL;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    init();

    simulate();
    print();

    return  0;
}