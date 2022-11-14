#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (200000+1)
#define WHITE       0

#define ALREADY_PAINTED(c1,c2)  (((c1)==(c2))?0:1)

int     N,expected[MAX_SIZE];
bool    visited[MAX_SIZE];

vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>expected[i];
    }

    for(int i=1;i<N;i++)
    {
        int a,b;

        cin>>a>>b;

        connected[a].push_back(b);
        connected[b].push_back(a);
    }
}

int     paint_color(int node,int prev_color)
{
    int ret;

    if( visited[node] == true )
    {
        return  0;
    }

    visited[node] = true;
    ret = ALREADY_PAINTED(prev_color,expected[node]);

    for(int i=0;i<connected[node].size();i++)
    {
        ret += paint_color(connected[node][i],expected[node]);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<paint_color(1,WHITE)<<'\n';

    return  0;
}