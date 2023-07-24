#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,m,k;
    bool    visited[MAX_SIZE] = {false,};

    cin>>n>>m>>k;

    for(int i=1;i<=m+k;i++)
    {
        int p;

        cin>>p;
        visited[p] = true;
    }

    cout<<n-(m+k)<<'\n';

    for(int i=1;i<=n;i++)
    {
        if(!visited[i]) cout<<i<<' ';
    }

    cout<<'\n';
    return  0;
}