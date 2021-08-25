#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (900+1)

int     N,K,F;
bool    friendly[MAX_SIZE][MAX_SIZE];

vector<int> my_friend[MAX_SIZE];

bool    can_be_friend(const vector<int>& current,int new_friend)
{
    for(int i=0;i<current.size();i++)
    {
        if( friendly[current[i]][new_friend] == false )
        {
            return  false;
        }
    }

    return  true;
}

bool    dfs(vector<int>& group)
{
    if( group.size() == K )
    {
        return  true;
    }

    int last_friend = group.back();

    for(int i=last_friend+1;i<=N;i++)
    {
        if( can_be_friend(group,i)==true )
        {
            group.push_back(i);

            if( dfs(group) == true )
            {
                return  true;
            }

            group.pop_back();
        }
    }

    return  false;
}

void    input(void)
{
    cin>>K>>N>>F;

    for(int i=1;i<=F;i++)
    {
        int f1,f2;

        cin>>f1>>f2;

        friendly[f1][f2] = friendly[f2][f1] = true;
        my_friend[min(f1,f2)].push_back(max(f1,f2));
    }
}

bool    find_group(vector<int>& group)
{
    for(int i=1;i<=N;i++)
    {
        group.push_back(i);

        if( dfs(group) == true )
        {
            return  true;
        }

        group.pop_back();
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> g;

    input();

    if( find_group(g) == false )
    {
        cout<<"-1\n";
    }
    else
    {
        for(int i=0;i<K;i++)
        {
            cout<<g[i]<<'\n';
        }
    }

    return  0;
}