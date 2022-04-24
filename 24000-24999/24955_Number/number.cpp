#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

typedef unsigned long long  uint64;
typedef pair<int,uint64>    State;  // first:house,second:number
typedef pair<int,int>       Query;  // first:from,second:to

#define MAX_SIZE    (1000+1)
#define MOD(n)      ((n)%1000000007)

int         N,Q,visited[MAX_SIZE];
uint64      num[MAX_SIZE];
vector<int> connected[MAX_SIZE];

uint64  get_num_for_shift(uint64 n)
{
    uint64   ret = 1;

    for(;n>0;n/=10,ret*=10);

    return  ret;
}

void    input(vector<Query>& q)
{
    cin>>N>>Q;

    for(int i=1;i<=N;i++)
    {
        cin>>num[i];
    }

    for(int i=1;i<=N-1;i++)
    {
        int a,b;

        cin>>a>>b;

        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    for(int i=1;i<=Q;i++)
    {
        Query   qu;

        cin>>qu.first>>qu.second;
        q.push_back(qu);
    }
}

uint64  bfs(int s,int e,int v)
{
    uint64           ret;
    queue<State>    q;

    visited[s] = v;
    q.push(make_pair(s,MOD(num[s])));

    for(;!q.empty();q.pop())
    {
        int     current_pos = q.front().first;
        uint64  current_num = q.front().second;

        if( current_pos == e )
        {
            ret = current_num;
            break;
        }

        vector<int>&    adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_pos = adj[i];

            if( visited[adj_pos] != v )
            {
                uint64  new_num = 
                            current_num*get_num_for_shift(num[adj_pos])+num[adj_pos];        
                
                visited[adj_pos] = v;
                q.push(make_pair(adj_pos,MOD(new_num)));
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Query>   q;

    input(q);

    for(int i=1;i<=Q;i++)
    {
        Query&  current = q[i-1];

        cout<<bfs(current.first,current.second,i)<<'\n';
    }

    return  0;
}