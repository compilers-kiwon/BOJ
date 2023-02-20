#include    <iostream>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (300000+1)

static int  N,A[MAX_SIZE],sum[MAX_SIZE];
static int  Q,L[MAX_SIZE],R[MAX_SIZE];

int input(void)
{
    cin>>N>>Q;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    for(int i=1;i<=Q;i++)
    {
        cin>>L[i]>>R[i];
    }

    return  0;
}

int get_sum(void)
{
    for(int i=1;i<=N;i++)
    {
        sum[i] = sum[i-1]+A[i];
    }

    return  0;
}

int process_query(void)
{
    for(int i=1;i<=Q;i++)
    {
        cout<<sum[R[i]]-sum[L[i]-1]<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    sort(&A[1],&A[N+1]);

    get_sum();
    process_query();

    return  0;
}