#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    100000
#define TBD         0

int         n,m,dp[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int c1,c2;

        cin>>c1>>c2;

        connected[c1].push_back(c2);
        connected[c2].push_back(c1);
    }
}

int     get_dp(int current_city)
{
    int&    ret = dp[current_city];

    if( ret != TBD )
    {
        return  ret;
    }

    for(int i=0;i<connected[current_city].size();i++)
    {
        int adj_city = connected[current_city][i];

        if( connected[adj_city].size() > connected[current_city].size() )
        {
            ret = max(ret,get_dp(adj_city));
        }
    }

    return  ++ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_num_of_cities = 0;

    input();

    for(int i=0;i<n;i++)
    {
        max_num_of_cities = max(max_num_of_cities,get_dp(i));
    }

    cout<<max_num_of_cities<<'\n';

    return  0;
}