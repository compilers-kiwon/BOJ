#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

int N,M,parent[MAX_SIZE];

typedef long long int       int64;
typedef pair<int,int>       Path;   // first:city1,second:city2
typedef pair<int64,Path>    State;  // first:-cost,second:Path

priority_queue<State>   pq;

int64   input(void)
{
    int64   ret = 0;

    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int     a,b;
        int64   c;

        cin>>a>>b>>c;

        ret += c;
        pq.push(make_pair(-c,make_pair(a,b)));
    }

    for(int i=1;i<=N;i++)
    {
        parent[i] = i;
    }

    return  ret;
}

int     find_parent(int n)
{
    int&    ret = parent[n];

    if( ret != n )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

int64   construct(void)
{
    int64   ret = 0;

    for(;!pq.empty();pq.pop())
    {
        int64   current_cost = -pq.top().first;
        int     current_city1 = pq.top().second.first;
        int     current_city2 = pq.top().second.second;

        int p1 = find_parent(current_city1);
        int p2 = find_parent(current_city2);

        if( p1 == p2 )
        {
            continue;
        }

        int big = max(p1,p2);
        int small = min(p1,p2);

        parent[big] = small;
        ret += current_cost;
    }

    bool    connected = true;

    for(int i=1;i<=N;i++)
    {
        if( find_parent(i) != 1 )
        {
            connected = false;
            break;
        }
    }

    return  ((connected!=true)?-1:ret);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   total_cost = input();
    int64   construction_cost = construct();

    if( construction_cost == -1 )
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<total_cost-construction_cost<<'\n';
    }

    return  0;
}