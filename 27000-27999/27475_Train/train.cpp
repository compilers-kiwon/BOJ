#include    <iostream>

using namespace std;

#define MAX_SIZE    100

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for(cin>>t;t>0;t--)
    {
        int     n,m,cnt;
        bool    v[MAX_SIZE+1] = {false,};

        cin>>n>>m;
        cnt = 0;

        for(int i=1;i<=n;i++)
        {
            int train;

            cin>>train;
            v[train] = true;
        }

        for(int i=1;i<=m;i++)
        {
            int train;

            cin>>train;
            cnt += v[train]?1:0;
        }

        cout<<cnt<<'\n';
    }

    return  0;
}