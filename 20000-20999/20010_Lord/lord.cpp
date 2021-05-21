#include    <iostream>
#include    <vector>
#include    <queue>
#include    <algorithm>

using namespace std;

#define MAX_VILLAGE     1000
#define MAX_NUM_OF_PATH 1000000
#define NONE            -1

typedef struct{int a,b,c;}  Path;       // first:cost,second:Village

int         N,K,visited[MAX_VILLAGE],parent[MAX_VILLAGE];
Path        p[MAX_NUM_OF_PATH];
vector<int> connected_path[MAX_VILLAGE],tree[MAX_VILLAGE];

void    input(void)
{
    cin>>N>>K;

    for(int i=0;i<K;i++)
    {
        int&    a = p[i].a;
        int&    b = p[i].b;
        int&    c = p[i].c;

        cin>>a>>b>>c;

        connected_path[a].push_back(i);
        connected_path[b].push_back(i);
    }
}

bool    is_shorter(const Path& p1,const Path& p2)
{
    return  (p1.c<=p2.c);
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

int     build_minimum_path(void)
{
    for(int i=0;i<N;i++)
    {
        parent[i] = i;
    }

    sort(&p[0],&p[K],is_shorter);

    int ret = 0;

    for(int i=0;i<K;i++)
    {
        const int&    a = p[i].a;
        const int&    b = p[i].b;
        const int&    c = p[i].c;

        int pa = find_parent(a);
        int pb = find_parent(b);

        if( pa == pb )
        {
            continue;
        }

        ret += c;
        parent[max(pa,pb)] = min(pa,pb);

        tree[a].push_back(i);
        tree[b].push_back(i);
    }

    return  ret;
}

int     find_furthermost_village(int from,int& max_distance)
{
    int         ret;
    queue<int>  vq;

    ret = from;
    max_distance = from;
    fill(&visited[0],&visited[N],NONE);
    
    vq.push(from);
    visited[from] = 0;
    
    for(;!vq.empty();vq.pop())
    {
        int current_visit = vq.front();

        vector<int>&    adj_path = tree[current_visit];

        for(int i=0;i<adj_path.size();i++)
        {
            Path&   current = p[adj_path[i]];
            int     adj_visit = ((current.a==current_visit)?current.b:current.a);
            
            if( visited[adj_visit] != NONE )
            {
                continue;
            }

            vq.push(adj_visit);
            visited[adj_visit] = visited[current_visit]+current.c;

            if( visited[adj_visit] > max_distance )
            {
                ret = adj_visit;
                max_distance = visited[adj_visit];
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
    cout<<build_minimum_path()<<'\n';

    int max_distance;

    find_furthermost_village(find_furthermost_village(0,max_distance),max_distance);
    cout<<max_distance<<'\n';

    return  0;
}