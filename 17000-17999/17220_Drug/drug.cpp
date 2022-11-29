#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    26
#define GET_IDX(c)  ((int)((c)-'A'))

int         N,M,K;
bool        arrested[MAX_SIZE];
vector<int> supplier,connected[MAX_SIZE];

#define mark_not_supplier(person,table) ((table)[GET_IDX((person))]=false)

void    input(void)
{
    bool    is_supplier[MAX_SIZE];

    cin>>N>>M;
    fill(&is_supplier[0],&is_supplier[MAX_SIZE],true);

    for(int i=1;i<=M;i++)
    {
        char    a,b;

        cin>>a>>b;

        connected[GET_IDX(a)].push_back(GET_IDX(b));
        mark_not_supplier(b,is_supplier);
    }

    cin>>K;

    for(int i=1;i<=K;i++)
    {
        char    c;

        cin>>c;
        arrested[GET_IDX(c)] = true;
    }

    for(int i=0;i<N;i++)
    {
        if( is_supplier[i]==true && arrested[i]==false )
        {
            supplier.push_back(i);
        }
    }
}

int     dfs(int current)
{
    int ret = 1;

    for(int i=0;i<connected[current].size();i++)
    {
        int&    adj = connected[current][i];

        if( arrested[adj] == false )
        {
            arrested[adj] = true;
            ret += dfs(adj);
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n = 0;

    input();

    for(int i=0;i<supplier.size();i++)
    {   
        n += dfs(supplier[i]);
    }

    cout<<n-supplier.size()<<'\n';

    return  0;
}