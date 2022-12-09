#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_SIZE    (500000+1)
#define NONE        ' '

int         N;
char        t[MAX_SIZE+1],handle[MAX_SIZE+1];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>&t[1];

    for(int i=1;i<N;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].push_back(v);
        connected[v].push_back(u);
    }
}

void    dfs(int parent,int current,int pos)
{
    char        c = NONE;
    vector<int> candidates;

    for(int i=0;i<connected[current].size();i++)
    {
        int&    adj =connected[current][i];

        if( adj!=parent && t[adj]>=c )
        {
            if( t[adj] > c )
            {
                candidates.clear();
            }

            c = t[adj];
            candidates.push_back(adj);
        }
    }

    if( c!=NONE && c>=handle[pos] )
    {
        if( c > handle[pos] )
        {
            handle[pos+1] = '\0';
        }

        handle[pos] = c;

        for(int i=0;i<candidates.size();i++)
        {
            dfs(current,candidates[i],pos+1);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    handle[0] = t[1];
    
    dfs(0,1,1);
    cout<<handle<<'\n';

    return  0;
}