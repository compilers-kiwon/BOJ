#include    <iostream>
#include    <vector>
#include    <queue>
#include    <set>

using namespace std;

#define MAX_SIZE            100
#define MAX_DIR             4
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define FALSE   0
#define TRUE    1

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int         n,m,grid[MAX_SIZE][MAX_SIZE];
bool        visited[MAX_SIZE][MAX_SIZE][2];
vector<int> height;

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<int,Pos>   State;  // first:already_jumped,second:Pos

void    input(void)
{
    set<int>    tmp;

    cin>>n>>m;

    for(int row=0;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
            cin>>grid[row][col];
            tmp.insert(grid[row][col]);
        }
    }

    for(set<int>::iterator it=tmp.begin();it!=tmp.end();it++)
    {
        height.push_back(*it);
    }
}

void    init_visited(void)
{
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
            visited[row][col][FALSE] = 
                visited[row][col][TRUE] = false;
        }
    }
}

bool    simulate(int h)
{
    bool            ret = false;
    queue<State>    q;

    if( h < grid[0][0] )
    {
        return  false;
    }

    init_visited();

    for(q.push(make_pair(FALSE,make_pair(0,0))),
            visited[0][0][FALSE]=true;!q.empty();q.pop())
    {
        int current_jump = q.front().first;
        int current_row = q.front().second.first;
        int current_col = q.front().second.second;

        if( current_row==n-1 && current_col==m-1 )
        {
            ret = true;
            break;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            int     adj_row,adj_col;
            bool    go;

            adj_row = current_row+adj[d].d_row;
            adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(0,adj_row,n-1) || !IN_RANGE(0,adj_col,m-1) ||
                    visited[adj_row][adj_col][current_jump]!=false || grid[adj_row][adj_col]>h )
            {
                go = false;
            }
            else
            {
                go = true;
            }

            if( go == true )
            {
                q.push(make_pair(current_jump,make_pair(adj_row,adj_col)));
                visited[adj_row][adj_col][current_jump] = true;
            }
            else
            {
                if( current_jump == TRUE )
                {
                    continue;
                }

                adj_row = current_row+adj[d].d_row*2;
                adj_col = current_col+adj[d].d_col*2;

                if( !IN_RANGE(0,adj_row,n-1) || !IN_RANGE(0,adj_col,m-1)
                        || visited[adj_row][adj_col][TRUE]!=false || grid[adj_row][adj_col]>h )
                {
                    continue;
                }

                q.push(make_pair(TRUE,make_pair(adj_row,adj_col)));
                visited[adj_row][adj_col][TRUE] = true;
            }
        }
    }

    return  ret;
}

int     escape(void)
{
    int ret;

    for(int left=0,right=height.size()-1;left<=right;)
    {
        int mid = (left+right)/2;
        
        if( simulate(height[mid]) == true )
        {
            ret = height[mid];
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<escape()<<'\n';

    return  0;
}