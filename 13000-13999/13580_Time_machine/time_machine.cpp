#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    3

#define PAST    -1
#define PRESENT 0
#define FUTURE  1

int t[MAX_SIZE];

#define TIME_TRAVEL(table,d) \
    {(table).push_back((d));if(dfs(table))return true;(table).pop_back();}

bool    all_zero(const vector<int>& dir)
{
    for(int i=0;i<dir.size();i++)
    {
        if( dir[i] != 0 )
        {
            return  false;
        }
    }

    return  true;
}

int     get_sum(const vector<int>& dir)
{
    int ret = 0;

    for(int i=0;i<MAX_SIZE;i++)
    {
        ret += t[i]*dir[i];
    }

    return  ret;
}

bool    dfs(vector<int>& dir)
{
    if( dir.size() == MAX_SIZE )
    {
        return  (all_zero(dir)==false&&get_sum(dir)==0);
    }

    TIME_TRAVEL(dir,PAST);
    TIME_TRAVEL(dir,PRESENT);
    TIME_TRAVEL(dir,FUTURE);

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=0;i<MAX_SIZE;i++)
    {
        cin>>t[i];
    }

    vector<int> dir;

    cout<<(dfs(dir)?'S':'N')<<'\n';

    return  0;
}