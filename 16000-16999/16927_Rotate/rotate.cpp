#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (300+1)

#define DOWN    0
#define RIGHT   1
#define UP      2
#define LEFT    3
#define MAX_DIR 4

int     N,M,R;
int     A[MAX_SIZE][MAX_SIZE];
int     rotated[MAX_SIZE][MAX_SIZE];
bool    visited[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{1,0},{0,1},{-1,0},{0,-1}};

typedef pair<int,int>   Pos;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

vector<vector<Pos>> connected;

void    get_connected(int s_row,int s_col,vector<Pos>& result)
{
    int row = s_row;
    int col = s_col;
    int dir = DOWN;

    visited[row][col] = true;
    result.push_back(make_pair(row,col));
    
    do{
        int adj_row = row+adj[dir].d_row;
        int adj_col = col+adj[dir].d_col;

        if( !IN_RANGE(1,adj_row,N)
            || !IN_RANGE(1,adj_col,M)
            || visited[adj_row][adj_col]==true )
        {
            dir++;
            continue;
        }

        row = adj_row;
        col = adj_col;

        visited[row][col] = true;
        result.push_back(make_pair(row,col));
        
    }while(dir<MAX_DIR);
}

void    init(void)
{
    for(int i=1;i<=min(N,M);i++)
    {
        if( visited[i][i] == false )
        {
            vector<Pos> v;

            get_connected(i,i,v);
            connected.push_back(v);
        }
    }
}

void    rotate(void)
{
    for(int i=0;i<connected.size();i++)
    {
        vector<Pos>&    v = connected[i];

        for(int from=0,to=R%v.size();from<v.size();from++,to=(to+1)%v.size())
        {
            int&    src_row = v[from].first;
            int&    src_col = v[from].second;
            int&    dst_row = v[to].first;
            int&    dst_col = v[to].second;

            rotated[dst_row][dst_col] = A[src_row][src_col];
        }
    }
}

void    input(void)
{
    cin>>N>>M>>R;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>A[row][col];
        }
    }
}


void    print(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cout<<rotated[row][col]<<' ';
        }

        cout<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();init();
    rotate();print();

    return  0;
}