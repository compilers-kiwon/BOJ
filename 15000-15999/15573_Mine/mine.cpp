#include    <iostream>

using namespace std;

#define MAX_SIZE        (1000+1)
#define MAX_DIR         4
#define MAX_STRENGTH    1000000
#define NONE            0

int     N,M,K,S[MAX_SIZE][MAX_SIZE];
bool    visited[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N>>M>>K;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>S[row][col];
        }
    }
}

int     dfs(int row,int col,int s)
{
    int ret = 0;

    if( visited[row][col]==true || S[row][col]>s )
    {
        return  ret;
    }

    ret = 1;
    visited[row][col] = true;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
        {
            continue;
        }

        ret += dfs(adj_row,adj_col,s);
    }

    return  ret;
}

int     mine_mineral(int strength)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        fill(&visited[row][1],&visited[row][M+1],false);
    }

    for(int row=1;row<=N;row++)
    {
        if( row == 1 )
        {
            for(int col=1;col<=M;col++)
            {
                ret += dfs(row,col,strength);
            }
        }
        else
        {
            ret += dfs(row,1,strength);
            ret += dfs(row,M,strength);
        }
    }

    return  ret;
}

int     simulate(void)
{
    int ret;

    for(int l=1,r=MAX_STRENGTH;l<=r;)
    {
        int mid = (l+r)/2;
        int num_to_be_mined = mine_mineral(mid);
        
        if( num_to_be_mined >= K )
        {
            ret = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}