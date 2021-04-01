#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (20000+1)
#define INF         0x7FFFFFFF

#define LEFT    0
#define RIGHT   1

#define FIRST   0
#define SECOND  1

int n,pos[MAX_SIZE][2],dp[MAX_SIZE][2][2];

typedef pair<int,int>   Pos;    // first:row,second:(LEFT/RIGHT)*10+(FIRST/SECOND)
typedef pair<int,Pos>   State;  // first:-path,second:Pos

void    input(void)
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>pos[i][0]>>pos[i][1];
        dp[i][LEFT][FIRST] = dp[i][LEFT][SECOND] = dp[i][RIGHT][FIRST] = dp[i][RIGHT][SECOND] = INF;
    }
}

int     bfs(void)
{
    int ret;
    priority_queue<State>   state_q;

    dp[1][LEFT][FIRST] = pos[1][LEFT]-1;
    state_q.push(make_pair(-(pos[1][LEFT]-1),make_pair(1,LEFT*10+FIRST)));

    dp[1][RIGHT][FIRST] = pos[1][RIGHT]-1;
    state_q.push(make_pair(-(pos[1][RIGHT]-1),make_pair(1,RIGHT*10+FIRST)));

    for(ret=INF;!state_q.empty();)
    {
        int current_path,current_row,current_col,current_order;

        current_path = -state_q.top().first;
        current_row = state_q.top().second.first;
 
        current_col = state_q.top().second.second/10;
        current_order = state_q.top().second.second%10;

        state_q.pop();

        if( current_row==n && current_order==SECOND )
        {
            ret = min(ret,current_path+(n-pos[n][current_col]));
            continue;
        }

        int adj_row,adj_col,adj_path;

        if( current_order == FIRST )
        {
            adj_row = current_row;
            adj_col = (current_col==LEFT)?RIGHT:LEFT;
            adj_path = current_path+abs(pos[current_row][current_col]-pos[adj_row][adj_col]);

            if( adj_path < dp[adj_row][adj_col][SECOND] )
            {
                dp[adj_row][adj_col][SECOND] = adj_path;
                state_q.push(make_pair(-adj_path,make_pair(adj_row,adj_col*10+SECOND)));
            }
        }
        else
        {
            adj_row = current_row+1;

            for(adj_col=LEFT;adj_col<=RIGHT;adj_col++)
            {
                adj_path = current_path+abs(pos[current_row][current_col]-pos[adj_row][adj_col])+1;

                if( adj_path < dp[adj_row][adj_col][FIRST] )
                {
                    dp[adj_row][adj_col][FIRST] = adj_path;
                    state_q.push(make_pair(-adj_path,make_pair(adj_row,adj_col*10+FIRST)));
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
    cout<<bfs()<<'\n';

    return  0;
}