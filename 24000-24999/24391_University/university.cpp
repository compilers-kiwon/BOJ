#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100000+1)
#define UNKNOWN     0

int         N,M,lecture[MAX_SIZE];
int         group_no[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int a,b;

        cin>>a>>b;

        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    for(int i=1;i<=N;i++)
    {
        cin>>lecture[i];
    }
}

void    dfs(int current_building,int group)
{
    if( group_no[current_building] != UNKNOWN )
    {
        return;
    }

    group_no[current_building] = group;

    for(int i=0;i<connected[current_building].size();i++)
    {
        dfs(connected[current_building][i],group);
    }
}

int     count_out_of_building(void)
{
    int ret = 0;
    int prev_group = group_no[lecture[1]];

    for(int i=1;i<=N;i++)
    {
        ret += ((prev_group!=group_no[lecture[i]])?1:0);
        prev_group = group_no[lecture[i]];
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=1;i<=N;i++)
    {
        if( group_no[i] == UNKNOWN )
        {
            dfs(i,i);
        }
    }

    cout<<count_out_of_building()<<'\n';

    return  0;
}