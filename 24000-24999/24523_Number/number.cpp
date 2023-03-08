#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000000+1)
#define NONE        -1

static int N,A[MAX_SIZE],idx[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    idx[N] = NONE;

    for(int i=N-1;i>=1;i--)
    {
        (A[i]==A[i+1])?idx[i]=idx[i+1]:idx[i]=i+1;
    }

    for(int i=1;i<=N;i++)
    {
        cout<<idx[i]<<' ';
    }

    cout<<'\n';
    return  0;
}