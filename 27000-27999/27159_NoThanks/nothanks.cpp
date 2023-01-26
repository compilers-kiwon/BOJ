#include    <iostream>
#include    <vector>

using namespace std;

#define tail_number(g)  ((g).back().back())

void    build_group(vector<vector<int>>& group)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int x;

        cin>>x;

        if( group.empty() || (x-tail_number(group))!=1 )
        {
            group.push_back(vector<int>());
        }

        group.back().push_back(x);
    }
}

int     get_score(const vector<vector<int>>& group)
{
    int ret = 0;

    for(int i=0;i<group.size();i++)
    {
        ret += group[i].front();
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<vector<int>> group;
    
    build_group(group);
    cout<<get_score(group)<<'\n';

    return  0;
}