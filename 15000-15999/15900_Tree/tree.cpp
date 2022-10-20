#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (500000+1)
#define ROOT        1
#define is_odd(n)   (((n)%2)==1)

int         N,total_distance;
bool        visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    dfs(int current,int dist)
{
    bool    leaf = true;

    for(int i=0;i<connected[current].size();i++)
    {
        int&    adj = connected[current][i];

        if( visited[adj] == false )
        {
            visited[adj] = true;
            dfs(adj,dist+1);
            leaf = false;
        }
    }

    if( leaf == true )
    {
        total_distance += dist;
    }
}

void    input(void)
{
     cin>>N;

     for(int i=1;i<N;i++)
     {
        int a,b;

        cin>>a>>b;

        connected[a].push_back(b);
        connected[b].push_back(a);
     }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    visited[ROOT] = true;
    dfs(ROOT,0);
    
    cout<<(is_odd(total_distance)?"Yes":"No")<<'\n';
    
    return  0;
}