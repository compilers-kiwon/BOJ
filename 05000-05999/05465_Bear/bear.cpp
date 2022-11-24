#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (800+1)
#define MAX_DIR     4
#define NONE        -1

typedef pair<int,int>       Pos;    // first:row,second:col
typedef struct{int t,r,c;}  State;  // t:time_to_visit,r:row,c:col

int     N,S;
int     corrupted_time[MAX_SIZE][MAX_SIZE];;
Pos     honey,home;
bool    visited[MAX_SIZE][MAX_SIZE];
char    grid[MAX_SIZE][MAX_SIZE+1];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define GREEN   'G'
#define HONEY   'M'
#define HOME    'D'
#define BEE     'H'
#define TREE    'T'

void    input(queue<Pos>& q)
{
    cin>>N>>S;
    
    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=N;col++)
        {
            char&   c = grid[row][col];

            corrupted_time[row][col] = NONE;

            switch(c)
            {
                case    HONEY:
                    honey = make_pair(row,col);
                    grid[row][col] = GREEN;
                    break;
                case    HOME:
                    home = make_pair(row,col);
                    break;
                case    BEE:
                    q.push(make_pair(row,col));
                    corrupted_time[row][col] = 0;
                    break;
                default:
                    // do nothing
                    break;
            }
        }
    }
}

void    get_corrupted_time(queue<Pos>& q)
{
    for(;!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) ||
                    grid[adj_row][adj_col]!=GREEN || corrupted_time[adj_row][adj_col]!=-1 )
            {
                continue;
            }

            q.push(make_pair(adj_row,adj_col));
            corrupted_time[adj_row][adj_col] = 
                corrupted_time[current_row][current_col]+S;
        }
    }
}

bool    can_go_home(int start_time)
{
    queue<State>  q;

    if( corrupted_time[honey.first][honey.second] != NONE &&
            start_time >= corrupted_time[honey.first][honey.second] )
    {
        return  false;
    }

    for(int row=1;row<=N;row++)
    {
        fill(&visited[row][1],&visited[row][N+1],false);
    }

    visited[honey.first][honey.second] = true;
    q.push({start_time,honey.first,honey.second});

    
    for(;!q.empty();q.pop())
    {
        int current_time = q.front().t;
        int current_row = q.front().r;
        int current_col = q.front().c;

        if( current_row==home.first && current_col==home.second )
        {
            return  true;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
            {
                continue;
            }

            if( grid[adj_row][adj_col] == TREE )
            {
                continue;
            }

            if( corrupted_time[adj_row][adj_col]!= NONE &&
                    current_time+1 >= corrupted_time[adj_row][adj_col] )
            {
                continue;
            }

            if( visited[adj_row][adj_col] == true )
            {
                continue;
            }

            visited[adj_row][adj_col] = true;
            q.push({current_time+1,adj_row,adj_col});
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<Pos>  q;
    int         max_time;

    input(q);
    get_corrupted_time(q);

    max_time = NONE;

    for(int left=0,right=MAX_SIZE*MAX_SIZE*S;left<=right;)
    {
        int mid = (left+right)/2;

        if( can_go_home(mid) == true )
        {
            max_time = mid;
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    cout<<((max_time!=NONE)?max_time/S:NONE)<<'\n';

    return  0;
}