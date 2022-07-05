#include    <iostream>

using namespace std;

#define MAX_NUM 6

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,cnt[MAX_NUM+1],latest_idx[MAX_NUM+1];

    cin>>n;
    fill(&cnt[1],&cnt[MAX_NUM+1],0);

    for(int i=1;i<=n;i++)
    {
        int a;

        cin>>a;

        cnt[a]++;
        latest_idx[a] = i;
    }

    int unique = 0;

    for(int i=MAX_NUM;i>=1;i--)
    {
        if( cnt[i] == 1 )
        {
            unique = latest_idx[i];
            break;
        }
    }

    if( unique == 0 )
    {
        cout<<"none\n";
    }
    else
    {
        cout<<unique<<'\n';
    }

    return  0;
}