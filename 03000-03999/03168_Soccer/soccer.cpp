#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

#define UP          -1
#define DOWN        1
#define NEXT_DIR(d) (-(d))

#define BALL        'L'
#define DEFENDER    '|'
#define EMPTY       '.'

typedef pair<int,int>   Defender;   // first:start_row,second:end_row

int         R,C,ball_row;
char        grid[MAX_SIZE][MAX_SIZE+1],result[MAX_SIZE][MAX_SIZE+1],current_ball[MAX_SIZE];
Defender    d[MAX_SIZE];

void    input(void)
{
    cin>>R>>C;

    for(int row=1;row<=R;row++)
    {
        cin>>&grid[row][1];        
    }
}

void    init(void)
{
    for(int row=1;row<=R;row++)
    {
        fill(&result[row][1],&result[row][C+1],EMPTY);
    }
}

void    get_ball_row(void)
{
    for(int row=1;row<=R;row++)
    {
        if( grid[row][1] == BALL )
        {
            ball_row = row;
            break;
        }
    }
}

bool    kick_ball(int dir)
{
    bool    ret = true;
    int     prev_row = ball_row;

    init();
    
    result[prev_row][1] = BALL;
    current_ball[1] = prev_row;

    for(int col=2;col<=C;col++)
    {
        if( (prev_row==1&&dir==UP) || (prev_row==R&&dir==DOWN) )
        {
            dir = NEXT_DIR(dir);
        }

        prev_row += dir;
        current_ball[col] = prev_row;
        result[prev_row][col] = BALL;
    }

    for(int col=2;ret!=false&&col<=C;col++)
    {
        int&    min_row = d[col].first;
        int&    max_row = d[col].second;
        int     required_len = max_row-min_row+1;
        bool    done_in_col = false;

        if( required_len <= 0 )
        {
            continue;
        }

        for(int row=1;done_in_col!=true&&row<=(R-required_len)+1;row++)
        {
            done_in_col = true;

            for(int src_row=min_row,dst_row=row;src_row<=max_row;src_row++,dst_row++)
            {
                if( grid[src_row][col] == EMPTY )
                {
                    continue;
                }

                if( result[dst_row][col] != EMPTY )
                {
                    done_in_col = false;
                    break;
                }
            }

            if( done_in_col == true )
            {
                for(int src_row=min_row,dst_row=row;src_row<=max_row;src_row++,dst_row++)
                {
                    if( grid[src_row][col] == DEFENDER )
                    {
                        result[dst_row][col] = DEFENDER;
                    }
                }
            }
        }

        ret = done_in_col;
    }

    return  ret;
}

void    print(void)
{
    for(int row=1;row<=R;row++)
    {
        cout<<grid[row][1]<<&result[row][2]<<'\n';
    }
}

void    get_defender_pos(void)
{
    for(int col=2;col<=C;col++)
    {
        int& min_row = d[col].first;
        int& max_row = d[col].second;

        min_row = MAX_SIZE;
        max_row = 0;

        for(int row=1;row<=R;row++)
        {
            if( grid[row][col] == DEFENDER )
            {
                min_row = min(min_row,row);
                max_row = max(max_row,row);
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_ball_row();
    get_defender_pos();

    for(int dir=UP;dir<=DOWN;dir=NEXT_DIR(dir))
    {
        if( kick_ball(dir) == true )
        {
            print();
            break;
        }
    }

    return  0;
}