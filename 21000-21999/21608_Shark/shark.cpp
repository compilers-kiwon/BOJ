#include    <iostream>
#include    <vector>
#include    <algorithm>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (20+1)
#define MAX_DIR     4
#define NONE        0
#define NUM_OF_LIKE 4

typedef pair<int,int>   Pos;
typedef pair<int,int>   State;

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int         N,grid[MAX_SIZE][MAX_SIZE];
vector<int> seat_order,like[MAX_SIZE*MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N*N;i++)
    {
        int n;

        cin>>n;
        seat_order.push_back(n);

        for(int j=1;j<=NUM_OF_LIKE;j++)
        {
            int l;

            cin>>l;
            like[n].push_back(l);
        }
    }
}

void    get_seat_info(int row,int col,int student,
                int& num_of_like,int& num_of_empty_seats)
{
    num_of_like = num_of_empty_seats = 0;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
        {
            continue;
        }

        if( grid[adj_row][adj_col] == NONE )
        {
            num_of_empty_seats++;
            continue;
        }

        vector<int>&    v = like[student];

        if( find(v.begin(),v.end(),grid[adj_row][adj_col]) != v.end() )
        {
            num_of_like++;
        }
    }
}

Pos     get_my_seat(int student)
{
    Pos     current_pos = make_pair(MAX_SIZE,MAX_SIZE);
    State   current_state = make_pair(-1,-1);

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            if( grid[row][col] != NONE )
            {
                continue;
            }

            Pos     adj_pos;
            State   adj_state;

            adj_pos = make_pair(row,col);
            get_seat_info(row,col,student,adj_state.first,adj_state.second);

            if( (current_state<adj_state) ||
                    (current_state==adj_state && adj_pos<current_pos) )
            {
                current_pos = adj_pos;
                current_state = adj_state;
            }
        }
    }

    return  current_pos;
}

void    assign_seat(void)
{
    for(int i=0;i<seat_order.size();i++)
    {
        Pos seat = get_my_seat(seat_order[i]);
        grid[seat.first][seat.second] = seat_order[i];
    }
}

int     get_score(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            int num_of_like,dummy;

            get_seat_info(row,col,grid[row][col],num_of_like,dummy);
            ret += ((num_of_like==0)?0:pow(10,num_of_like-1));
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    assign_seat();
    cout<<get_score()<<'\n';

    return  0;
}