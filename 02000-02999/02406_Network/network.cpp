#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef pair<int,int>       Connected;  // first:computer1,second:computer2
typedef pair<int,Connected> Cable;      // first:-cost,second:Connected

int n,m,parent[MAX_SIZE],table[MAX_SIZE][MAX_SIZE];

vector<Connected>       exist,built;
priority_queue<Cable>   pq;

void    input(void)
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;

        cin>>a>>b;
        exist.push_back(make_pair(a,b));
    }

    for(int row=1;row<=n;row++)
    {
        for(int col=1;col<=n;col++)
        {
            cin>>table[row][col];
        }
    }

    for(int i=0;i<exist.size();i++)
    {
        int&    a = exist[i].first;
        int&    b = exist[i].second;

        table[a][b] = table[b][a] = 0;
    }

    for(int row=2;row<=n;row++)
    {
        for(int col=row+1;col<=n;col++)
        {
            int&    c = table[row][col];

            if( c > 0 )
            {
                pq.push(make_pair(-c,make_pair(row,col)));
            }
        }

        parent[row] = row;
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

bool    connect_network(Connected c)
{
    int p1 = find_parent(c.first);
    int p2 = find_parent(c.second);

    if( p1 == p2 )
    {
        return  false;
    }

    parent[max(p1,p2)] = min(p1,p2);

    return  true;
}

int     build_network(void)
{
    int ret = 0;

    for(int i=0;i<exist.size();i++)
    {
        connect_network(exist[i]);
    }

    for(;!pq.empty();pq.pop())
    {
        int         cost = -pq.top().first;
        Connected   c = pq.top().second;

        if( connect_network(c) == true )
        {
            ret += cost;
            built.push_back(c);
        }
    }

    return  ret;
}

void    print(int X,int K)
{
    cout<<X<<' '<<K<<'\n';

    for(int i=0;i<K;i++)
    {
        cout<<built[i].first<<' '<<built[i].second<<'\n';
    }
}

int     main(void)
{
    int X,K;

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    X = build_network();

    K = built.size();
    print(X,K);

    return  0;
}