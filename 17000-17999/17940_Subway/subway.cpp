#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    1000
#define INF         0x7FFFFFFF
#define NONE        0
#define START       0

// first:<first:-num_of_transfers,second:-total_cost>,second:station
typedef pair<pair<int,int>,int> State;

// first:station,second:cost
typedef pair<int,int>           Path;

int N,M,C[MAX_SIZE];
int dp_cost[MAX_SIZE],dp_transfer[MAX_SIZE];

vector<Path>    connected[MAX_SIZE];

int     get_min_cost(int& num_of_transfer)
{
    priority_queue<State>    q;

    q.push(make_pair(make_pair(0,0),START));
    dp_cost[START] = dp_transfer[START] = 0;

    for(;!q.empty();)
    {
        int current_pos = q.top().second;
        int current_cost = -q.top().first.second;
        int current_num_of_transfers = -q.top().first.first;

        q.pop();

        if( current_pos == M )
        {
            break;
        }

        if( current_num_of_transfers > dp_transfer[current_pos] ||
                (current_num_of_transfers==dp_transfer[current_pos]&&current_cost>dp_cost[current_pos]) )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_cost = current_cost+adj[i].second;
            int adj_transfer = current_num_of_transfers
                                +((C[current_pos]!=C[adj_pos])?1:0);
            
            if( adj_transfer < dp_transfer[adj_pos] ||
                    (adj_transfer==dp_transfer[adj_pos]&&adj_cost<dp_cost[adj_pos]) )
            {
                q.push(make_pair(make_pair(-adj_transfer,-adj_cost),adj_pos));

                dp_cost[adj_pos] = adj_cost;
                dp_transfer[adj_pos] = adj_transfer;
            }
        }
    }

    num_of_transfer = dp_transfer[M];
    return  dp_cost[M];
}

void    input(void)
{
    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        cin>>C[i];
        dp_cost[i] = dp_transfer[i] = INF;
    }

    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            int E;

            cin>>E;

            if( E == NONE )
            {
                continue;
            }

            connected[row].push_back(make_pair(col,E));
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int min_cost,min_transfer;

    input();
    min_cost = get_min_cost(min_transfer);

    cout<<min_transfer<<' '<<min_cost<<'\n';

    return  0;
}