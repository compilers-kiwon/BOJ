#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)
#define char2int(c) ((int)((c)-'0'))

int     N;
char    grid[MAX_SIZE][MAX_SIZE+1];

typedef pair<int,int>   Pos;

void    input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }
}

void    init(void)
{
    if( char2int(grid[1][1]) == 0 )
    {
        grid[2][2] = ' ';
    }
    else
    {
        grid[2][2] = '*';
    }

    if( char2int(grid[N][1]) == 0 )
    {
        grid[N-1][2] = ' ';
    }
    else
    {
        grid[N-1][2] = '*';
    }

    if( char2int(grid[1][N]) == 0 )
    {
        grid[2][N-1] = ' ';
    }
    else
    {
        grid[2][N-1] = '*';
    }

    if( char2int(grid[N][N]) == 0 )
    {
        grid[N-1][N-1] = ' ';
    }
    else
    {
        grid[N-1][N-1] = '*';
    }
}

void   install_mine(void)
{
    for(;;)
    {
        bool    updated = false;

        for(int row=1,col=2;col<=N-1;col++)
        {
            int num_of_adj_mine = char2int(grid[row][col]);
            int mine,empty,unknown;
            Pos p[3];

            mine = empty = unknown = 0;

            for(int d=-1;d<=1;d++)
            {
                switch(grid[row+1][col+d])
                {
                    case    '*':
                        mine++;
                        break;
                    case    ' ':
                        empty++;
                        break;
                    case    '#':
                        p[unknown] = make_pair(row+1,col+d);
                        unknown++;
                    default:
                        // do nothing
                        break;
                }
            }

            if( unknown == 0 )
            {
                continue;
            }

            if( num_of_adj_mine == mine )
            {
                for(int i=0;i<unknown;i++)
                {
                    int&    row = p[i].first;
                    int&    col = p[i].second;

                    grid[row][col] = ' ';
                    updated = true;
                }
            }

            if( num_of_adj_mine == mine+unknown )
            {
                for(int i=0;i<unknown;i++)
                {
                    int&    row = p[i].first;
                    int&    col = p[i].second;

                    grid[row][col] = '*';
                    updated = true;
                }
            }
        }

        for(int row=N,col=2;col<=N-1;col++)
        {
            int num_of_adj_mine = char2int(grid[row][col]);
            int mine,empty,unknown;
            Pos p[3];

            mine = empty = unknown = 0;

            for(int d=-1;d<=1;d++)
            {
                switch(grid[row-1][col+d])
                {
                    case    '*':
                        mine++;
                        break;
                    case    ' ':
                        empty++;
                        break;
                    case    '#':
                        p[unknown] = make_pair(row-1,col+d);
                        unknown++;
                    default:
                        // do nothing
                        break;
                }
            }

            if( unknown == 0 )
            {
                continue;
            }

            if( num_of_adj_mine == mine )
            {
                for(int i=0;i<unknown;i++)
                {
                    int&    row = p[i].first;
                    int&    col = p[i].second;

                    grid[row][col] = ' ';
                    updated = true;
                }
            }

            if( num_of_adj_mine == mine+unknown )
            {
                for(int i=0;i<unknown;i++)
                {
                    int&    row = p[i].first;
                    int&    col = p[i].second;

                    grid[row][col] = '*';
                    updated = true;
                }
            }
        }

        for(int row=2,col=1;row<=N-1;row++)
        {
            int num_of_adj_mine = char2int(grid[row][col]);
            int mine,empty,unknown;
            Pos p[3];

            mine = empty = unknown = 0;

            for(int d=-1;d<=1;d++)
            {
                switch(grid[row+d][col+1])
                {
                    case    '*':
                        mine++;
                        break;
                    case    ' ':
                        empty++;
                        break;
                    case    '#':
                        p[unknown] = make_pair(row+d,col+1);
                        unknown++;
                    default:
                        // do nothing
                        break;
                }
            }

            if( unknown == 0 )
            {
                continue;
            }

            if( num_of_adj_mine == mine )
            {
                for(int i=0;i<unknown;i++)
                {
                    int&    row = p[i].first;
                    int&    col = p[i].second;

                    grid[row][col] = ' ';
                    updated = true;
                }
            }

            if( num_of_adj_mine == mine+unknown )
            {
                for(int i=0;i<unknown;i++)
                {
                    int&    row = p[i].first;
                    int&    col = p[i].second;

                    grid[row][col] = '*';
                    updated = true;
                }
            }
        }

        for(int row=2,col=N;row<=N-1;row++)
        {
            int num_of_adj_mine = char2int(grid[row][col]);
            int mine,empty,unknown;
            Pos p[3];

            mine = empty = unknown = 0;

            for(int d=-1;d<=1;d++)
            {
                switch(grid[row+d][col-1])
                {
                    case    '*':
                        mine++;
                        break;
                    case    ' ':
                        empty++;
                        break;
                    case    '#':
                        p[unknown] = make_pair(row+d,col-1);
                        unknown++;
                    default:
                        // do nothing
                        break;
                }
            }

            if( unknown == 0 )
            {
                continue;
            }

            if( num_of_adj_mine == mine )
            {
                for(int i=0;i<unknown;i++)
                {
                    int&    row = p[i].first;
                    int&    col = p[i].second;

                    grid[row][col] = ' ';
                    updated = true;
                }
            }

            if( num_of_adj_mine == mine+unknown )
            {
                for(int i=0;i<unknown;i++)
                {
                    int&    row = p[i].first;
                    int&    col = p[i].second;

                    grid[row][col] = '*';
                    updated = true;
                }
            }
        }

        if( updated == false )
        {
            break;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int cnt = 0;

        input();
        
        if( N <= 2 )
        {
            cout<<"0\n";
            continue;
        }

        init();
        install_mine();

        for(int row=2;row<=N-1;row++)
        {
            for(int col=2;col<=N-1;col++)
            {
                if( grid[row][col] != ' ' )
                {
                    cnt++;
                }
            }
        }

        cout<<cnt<<'\n';
    }

    return  0;
}