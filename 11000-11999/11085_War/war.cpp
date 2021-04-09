#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    1000
#define MAX_WIDTH   1000

typedef pair<int,int>   Path;   // first:to,second:width
typedef pair<int,int>   State;  // first:min_width,second:city

int             p,w,c,v,dp[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>p>>w>>c>>v;

    for(int i=1;i<=w;i++)
    {
        int start,end,width;

        cin>>start>>end>>width;

        connected[start].push_back(make_pair(end,width));
        connected[end].push_back(make_pair(start,width));
    }
}

int     move_soldier(void)
{
    int                     ret;
    priority_queue<State>   state_q;

    dp[c] = MAX_WIDTH;
    state_q.push(make_pair(MAX_WIDTH,c));

    for(;!state_q.empty();)
    {
        int current_city,current_min_width;

        current_min_width = state_q.top().first;
        current_city = state_q.top().second;

        state_q.pop();

        if( current_city == v )
        {
            ret = current_min_width;
            break;
        }

        vector<Path>&   adj = connected[current_city];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_city = adj[i].first;
            int&    adj_width = adj[i].second;
            int     min_width = min(current_min_width,adj_width);

            if( min_width <= dp[adj_city] )
            {
                continue;
            }

            dp[adj_city] = min_width;
            state_q.push(make_pair(min_width,adj_city));
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<move_soldier()<<'\n';

    return  0;
}