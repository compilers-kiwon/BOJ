#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_DIR     4

#define NONE        0
#define NOT_VISITED -1

typedef pair<int,int>   Pos;    // first:row,second:col

int     H,W,O,F,Xs,Ys,Xe,Ye;
int     grid[MAX_SIZE][MAX_SIZE];
int     dp[MAX_SIZE][MAX_SIZE];
bool    is_queued[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define enqueue(q,r,c)  {(q).push(make_pair((r),(c)));is_queued[(r)][(c)]=true;}
#define dequeue(q,r,c)  {(q).pop();is_queued[(r)][(c)]=false;}

void    init(void)
{
    for(int row=1;row<=H;row++)
    {
        fill(&grid[row][1],&grid[row][W+1],NONE);
        fill(&dp[row][1],&dp[row][W+1],NOT_VISITED);
        fill(&is_queued[row][1],&is_queued[row][W+1],false);
    }
}

void    input(void)
{
    cin>>H>>W>>O>>F>>Xs>>Ys>>Xe>>Ye;

    init();

    for(int i=1;i<=O;i++)
    {
        int X,Y,L;

        cin>>X>>Y>>L;
        grid[X][Y] = L;
    }
}

bool    get_trained(void)
{
    queue<Pos>  q;

    enqueue(q,Xs,Ys);
    dp[Xs][Ys] = F;

    for(;!q.empty();)
    {
        int current_row = q.front().first;
        int current_col = q.front().second;
        int current_pwr = dp[current_row][current_col];

        dequeue(q,current_row,current_col);

        if( current_row==Xe && current_col==Ye )
        {
            return  true;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,H) || !IN_RANGE(1,adj_col,W) )
            {
                continue;
            }

            int required_pwr = max(grid[adj_row][adj_col]
                                        -grid[current_row][current_col],0);

            if( required_pwr>current_pwr 
                    || dp[current_row][current_col]-1<=dp[adj_row][adj_col] )
            {
                continue;
            }

            if( is_queued[adj_row][adj_col] == false )
            {
                enqueue(q,adj_row,adj_col);
            }

            dp[adj_row][adj_col] = dp[current_row][current_col]-1;
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        input();
        cout<<(get_trained()?"잘했어!!":"인성 문제있어??")<<'\n';
    }

    return  0;
}