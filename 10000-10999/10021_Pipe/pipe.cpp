#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (2000+1)
#define ROOT        1

typedef pair<int,int>   Pos;    // first:x,second:y
typedef pair<int,Pos>   Pipe;   // first:-cost,<first:field1,second:field2>

int     N,C,parent[MAX_SIZE];
Pos     field[MAX_SIZE];

priority_queue<Pipe>    pq;

int     get_distance(int p1,int p2)
{
    int&    x1 = field[p1].first;
    int&    y1 = field[p1].second;
    int&    x2 = field[p2].first;
    int&    y2 = field[p2].second;
    
    int     dx = x1-x2;
    int     dy = y1-y2;

    return  ((dx*dx)+(dy*dy));
}

void    input(void)
{
    cin>>N>>C;

    for(int i=1;i<=N;i++)
    {
        cin>>field[i].first>>field[i].second;
    }
}

void    get_pipes(void)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            int d = get_distance(i,j);

            if( d < C )
            {
                continue;
            }

            pq.push(make_pair(-d,make_pair(i,j)));
        }

        parent[i] = i;
    }
}

int     find_parent(int me)
{
    int&    ret = parent[me];

    if( ret != me )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

bool    all_connected(void)
{
    for(int i=1;i<=N;i++)
    {
        if( find_parent(i) != ROOT )
        {
            return  false;
        }
    }

    return  true;
}

int     install_pipes(void)
{
    int ret = 0;

    for(;!pq.empty();pq.pop())
    {
        int cost = -pq.top().first;
        int f1 = pq.top().second.first;
        int f2 = pq.top().second.second;

        int p1 = find_parent(f1);
        int p2 = find_parent(f2);

        if( p1 == p2 )
        {
            continue;
        }

        parent[max(p1,p2)] = min(p1,p2);
        ret += cost;
    }

    return  ((all_connected())?ret:-1);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_pipes();

    cout<<install_pipes()<<'\n';

    return  0;
}