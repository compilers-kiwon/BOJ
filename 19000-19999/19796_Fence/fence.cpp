#include    <iostream>

using namespace std;

#define MAX_SIZE    (10000+1)

static bool filled[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int m,n,cnt;

    cin>>m>>n;
    cnt = 0;

    for (int i=1;i<=n;i++) {
        int l,r;
        cin>>l>>r;

        for (int pos=l;pos<=r;pos++) {
            if (!filled[pos]) cnt++,filled[pos]=true;
        }
    }

    cout<<(cnt==m?"YES":"NO")<<'\n';

    return  0;
}