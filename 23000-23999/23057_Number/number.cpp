#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE    (20+1)

int         N,M,num[MAX_SIZE];
set<int>    sum;

void    dfs(int idx,int current_sum)
{
    if( idx > N )
    {
        sum.insert(current_sum);
        return;
    }

    dfs(idx+1,current_sum+num[idx]);
    dfs(idx+1,current_sum);
}

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>num[i];
        M += num[i];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    dfs(1,0);

    cout<<M-(sum.size()-1)<<'\n';

    return  0;
}