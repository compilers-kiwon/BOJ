#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (200+1)

typedef struct{int x,y,p;}  Cow;

int N;
Cow c[MAX_SIZE];

vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>c[i].x>>c[i].y>>c[i].p;
    }
}

int     get_distance(int c1,int c2)
{
    int dx = c[c1].x-c[c2].x;
    int dy = c[c1].y-c[c2].y;

    return  (dx*dx)+(dy*dy);
}

void    get_connected(void)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if( i == j )
            {
                continue;
            }

            int dist = get_distance(i,j);

            if( dist <= c[i].p*c[i].p )
            {
                connected[i].push_back(j);
            }
        }
    }
}

int     dfs(int current,bool* visited)
{
    int ret = 0;

    if( visited[current] == true )
    {
        return  0;
    }

    visited[current] = true;

    for(int i=0;i<connected[current].size();i++)
    {
        ret += dfs(connected[current][i],visited);
    }

    return  (1+ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_num_of_broacast = 0;

    input();
    get_connected();

    for(int i=1;i<=N;i++)
    {
        bool    visited[MAX_SIZE] = {0,};

        max_num_of_broacast = max(max_num_of_broacast,dfs(i,visited));
    }

    cout<<max_num_of_broacast<<'\n';

    return  0;
}