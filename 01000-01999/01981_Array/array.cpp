#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_DIR     4

#define MIN_NUM 0
#define MAX_NUM 200

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

static int  n,arr[MAX_SIZE][MAX_SIZE];
static bool visited[MAX_SIZE][MAX_SIZE];

typedef pair<int,int> State;

#define row first
#define col second

#define TRUE    1
#define FALSE   0

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define INIT(q,v)           ((q).push({1,1}),(v)[1][1]=true)

int bfs(int min_num,int max_num)
{
    queue<State>    q;
    
    for(INIT(q,visited);!q.empty();q.pop())
    {
        int current_row = q.front().row;
        int current_col = q.front().col;

        if( current_row==n && current_col==n )
        {
            return  TRUE;
        }
        
        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,n) || !IN_RANGE(1,adj_col,n) )
            {
                continue;
            }

            if( visited[adj_row][adj_col]==false &&
                    IN_RANGE(min_num,arr[adj_row][adj_col],max_num) )
            {
                q.push({adj_row,adj_col});
                visited[adj_row][adj_col] = true;
            }
        }
    }

    return  FALSE;
}

int move(int max_diff)
{
    for(int i=MIN_NUM;i+max_diff<=MAX_NUM;i++)
    {
        if( !IN_RANGE(i,arr[1][1],i+max_diff) )
        {
            continue;
        }

        for(int row=1;row<=n;row++)
        {
            fill(&visited[row][1],&visited[row][n+1],false);
        }

        if( bfs(i,i+max_diff) == TRUE )
        {
            return  TRUE;
        }
    }

    return  FALSE;
}

int simulate(void)
{
    int low,high,ret;

    for(low=MIN_NUM,high=MAX_NUM;low<=high;)
    {
        int mid = (low+high)/2;
        
        if( move(mid) == TRUE )
        {
            ret = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n;

    for(int row=1;row<=n;row++)
    {
        for(int col=1;col<=n;col++)
        {
            cin>>arr[row][col];
        }
    }

    cout<<simulate()<<'\n';

    return  0;
}