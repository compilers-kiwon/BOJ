#include    <iostream>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_DIR 12
#define NONE    0
#define OFFSET  2

typedef pair<int,int>   Pos;    // first:x,second:y

int                     n,T;
map<int,map<int,bool>>  is_grap;
map<int,map<int,int>>   dp;

void    input(void)
{
    cin>>n>>T;

    for(int i=1;i<=n;i++)
    {
        int x,y;

        cin>>x>>y;
        is_grap[x][y] = true;
    }
}

int     simulate(void)
{
    int         ret = -1;
    queue<Pos>  q;

    dp[0][0] = 1;
    q.push(make_pair(0,0));

    for(;!q.empty();q.pop())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        int current_step = dp[current_x][current_y];
        
        if( current_y == T )
        {
            ret = current_step-1;
            break;
        }

        for(int dx=-OFFSET;dx<=OFFSET;dx++)
        {
            for(int dy=-OFFSET;dy<=OFFSET;dy++)
            {
                int adj_x = current_x+dx;
                int adj_y = current_y+dy;

                if( is_grap[adj_x][adj_y] == false )
                {
                    continue;
                }

                if( dp[adj_x][adj_y] == NONE )
                {
                    dp[adj_x][adj_y] = current_step+1;
                    q.push(make_pair(adj_x,adj_y));
                }
            }
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