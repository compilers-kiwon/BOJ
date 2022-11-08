#include    <iostream>
#include    <queue>
#include    <set>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_HEIGHT  20
#define INF         0x7FFFFFFF

typedef pair<int,int>   Pos;

int         N,K,dp[MAX_SIZE][MAX_HEIGHT+1];
set<int>    hole[MAX_SIZE];

void    input(void)
{
    cin>>N>>K;

    for(int row=1;row<=N;row++)
    {
        int M;

        cin>>M;

        for(int j=1;j<=M;j++)
        {
            int h;

            cin>>h;
            hole[row].insert(h);
        }

        fill(&dp[row][0],&dp[row][MAX_HEIGHT+1],INF);
    }
}

void    find_hole(int current_row,int current_col,
                    int offset,bool T_used,queue<Pos>& q)
{
    int adj_row = current_row+1;
    int adj_col = min(current_col+offset,MAX_HEIGHT);

    if( T_used == false )
    {
        if( hole[adj_row].find(adj_col)!=hole[adj_row].end() 
                && dp[current_row][current_col]<dp[adj_row][adj_col] )
        {
            q.push(make_pair(adj_row,adj_col));
            dp[adj_row][adj_col] = dp[current_row][current_col];
        }
    }
    else
    {
        for(int h=1;h<=MAX_HEIGHT;h++)
        {
            if( hole[adj_row].find(h)!=hole[adj_row].end() 
                    && dp[current_row][current_col]+1<dp[adj_row][h] )
            {
                q.push(make_pair(adj_row,h));
                dp[adj_row][h] = dp[current_row][current_col]+1;
            }
        }
    }
}

int     fly(void)
{
    int         ret;
    queue<Pos>  q;

    dp[0][1] = 0;
    q.push(make_pair(0,1));

    for(ret=INF;!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        if( current_row == N )
        {
            ret = min(ret,dp[current_row][current_col]);
            continue;
        }

        // 1. 'O'
        find_hole(current_row,current_col,0,false,q);

        // 2.'A'
        find_hole(current_row,current_col,1,false,q);

        // 3.'B'
        find_hole(current_row,current_col,current_col,false,q);

        // 4.'C'
        find_hole(current_row,current_col,-1,false,q);

        // 5.'T'
        if( dp[current_row][current_col] < K )
        {
            find_hole(current_row,current_col,0,true,q);
        }
    }

    return  ((ret==INF)?-1:ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<fly()<<'\n';

    return  0;
}