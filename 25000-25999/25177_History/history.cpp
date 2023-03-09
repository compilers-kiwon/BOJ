#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  N,M,a[MAX_SIZE],b[MAX_SIZE];

int input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++) cin>>a[i];
    for(int i=1;i<=M;i++) cin>>b[i];

    return  0;
}

int restore(void)
{
    int ret = 0;

    for(int i=1;i<=M;i++)
    {
        ret = max(ret,b[i]-a[i]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<restore()<<'\n';

    return  0;
}