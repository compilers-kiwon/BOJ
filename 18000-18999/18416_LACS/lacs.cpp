#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)
#define INF         0x7FFFFFFF

static int  N,A[MAX_SIZE];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    return  0;
}

int solve(void)
{
    int ret,cnt;

    ret = cnt = 0;
    A[0] = INF;

    for(int i=1;i<=N;i++)
    {
        cnt = (A[i]>=A[i-1])?cnt+1:1;
        ret = max(ret,cnt);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<solve()<<'\n';

    return  0;
}