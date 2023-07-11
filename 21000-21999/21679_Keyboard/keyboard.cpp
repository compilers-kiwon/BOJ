#include    <iostream>

using namespace std;

#define MAX_SIZE    (100000+1)

static int  n,c[MAX_SIZE],k;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }

    cin>>k;

    for(int i=1;i<=k;i++)
    {
        int p;

        cin>>p;
        c[p]--;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<((c[i]>=0)?"no":"yes")<<'\n';
    }

    return  0;
}