#include    <iostream>

using namespace std;

#define MAX_SIZE    (5000+1)

static int  N,A[MAX_SIZE];
static int  dp_from_head[MAX_SIZE],dp_from_tail[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    dp_from_head[1] = 1;

    for(int i=2;i<=N;i++)
    {
        dp_from_head[i] =
            (A[i]>A[i-1])?dp_from_head[i-1]+1:1;
    }

    dp_from_tail[N] = 1;

    for(int i=N-1;i>=1;i--)
    {
        dp_from_tail[i] =
            (A[i]>A[i+1])?dp_from_tail[i+1]+1:1;
    }

    int max_len = 0;

    for(int i=1;i<=N;i++)
    {
        max_len = max(max_len,
                dp_from_head[i]+dp_from_tail[i]-1);
    }

    cout<<max_len<<'\n';
    return  0;
}