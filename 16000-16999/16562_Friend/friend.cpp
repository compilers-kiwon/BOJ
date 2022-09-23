#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (10000+1)

int         N,M,k,cost[MAX_SIZE];
bool        visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>k;

    for(int i=1;i<=N;i++)
    {
        cin>>cost[i];
    }

    for(int i=1;i<=M;i++)
    {
        int v,w;

        cin>>v>>w;

        connected[v].push_back(w);
        connected[w].push_back(v);
    }
}

int     get_min_cost(int n)
{
    queue<int>  q;
    int         ret = cost[n];

    for(q.push(n),visited[n]=true;!q.empty();q.pop())
    {
        int             current = q.front();
        vector<int>&    adj = connected[current];

        for(int i=0;i<adj.size();i++)
        {
            if( visited[adj[i]] == false )
            {
                q.push(adj[i]);
                visited[adj[i]] = true;
                ret = min(ret,cost[adj[i]]);
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int total_cost;

    input();
    total_cost = 0;

    for(int i=1;i<=N;i++)
    {
        if( visited[i] == false )
        {
            total_cost += get_min_cost(i);
        }
    }

    if( total_cost > k )
    {
        cout<<"Oh no\n";
    }
    else
    {
        cout<<total_cost<<'\n';
    }

    return  0;
}