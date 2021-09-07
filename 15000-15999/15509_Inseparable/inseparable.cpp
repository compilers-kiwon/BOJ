#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    1000

int         n,m,k;
bool        visited[MAX_SIZE+1],dp[MAX_SIZE+1];
vector<int> jar[MAX_SIZE+1];

void    input(void)
{
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++)
    {
        int j1,j2;

        cin>>j1>>j2;

        jar[j1].push_back(j2);
        jar[j2].push_back(j1);
    }
}

int     dfs(int current_jar)
{
    if( visited[current_jar] == true )
    {
        return  0;
    }

    int             ret = 1;
    vector<int>&    adj = jar[current_jar];

    visited[current_jar] = true;

    for(int i=0;i<adj.size();i++)
    {
        ret += dfs(adj[i]);
    }

    return  ret;
}

void    count_inseparable_jars(vector<int>& size_of_group)
{
    for(int i=1;i<=n;i++)
    {
        int s;

        if( (s=dfs(i)) != 0 )
        {
            size_of_group.push_back(s);
        }
    }

    sort(size_of_group.begin(),size_of_group.end());
}

bool    get_dp(vector<int>& size_of_group)
{
    dp[0] = true;

    for(int i=0;i<size_of_group.size();i++)
    {
        int&    current_size = size_of_group[i];

        for(int s=MAX_SIZE-current_size;s>=0;s--)
        {
            if( dp[s] == true )
            {
                dp[s+current_size] = true;
            }
        }
    }

    return  dp[k];
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> group;

    input();
    count_inseparable_jars(group);

    if( get_dp(group) == true )
    {
        cout<<"SAFE\n";
    }
    else
    {
        cout<<"DOOMED\n";
    }

    return  0;
}