#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE        (100000+1)
#define TBD             -1LL
#define END_OF_INPUT    -1

typedef long long int   int64;
typedef pair<int,int64> Path;   // first:node,second:distance

int             V;
int64           dp[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>V;

    for(int i=1;i<=V;i++)
    {
        int     v,adj;
        int64   d;

        cin>>v;

        for(;;)
        {
            cin>>adj;

            if( adj == END_OF_INPUT )
            {
                break;
            }

            cin>>d;
            connected[v].push_back(make_pair(adj,d));
        }
    }
}

Path    get_farthest_node_and_distance(int from)
{
    int         frathest_node;
    int64       max_distance;
    queue<Path> q;

    dp[from] = 0;
    q.push(make_pair(from,0));

    for(frathest_node=from,max_distance=0;!q.empty();q.pop())
    {
        int     current_node = q.front().first;
        int64   current_dist = q.front().second;

        if( current_dist > dp[current_node] )
        {
            continue;
        }

        if( current_dist > max_distance )
        {
            max_distance = current_dist;
            frathest_node = current_node;
        }

        vector<Path>&   adj = connected[current_node];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_node = adj[i].first;
            int64&  adj_dist = adj[i].second;

            if( dp[adj_node]==TBD || current_dist+adj_dist<dp[adj_node] )
            {
                dp[adj_node] = current_dist+adj_dist;
                q.push(make_pair(adj_node,current_dist+adj_dist));
            }
        }
    }

    return  make_pair(frathest_node,max_distance);
} 

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Path    ret;

    input();
    fill(&dp[1],&dp[V+1],TBD);

    ret = get_farthest_node_and_distance(1);
    fill(&dp[1],&dp[V+1],TBD);
    
    ret = get_farthest_node_and_distance(ret.first);
    cout<<ret.second<<'\n';

    return  0;
}