#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1000+1)

static int  N,M,S[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        cin>>S[i];
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N+M;j++)
        {
            int T;

            cin>>T;

            S[i] -= T;
            S[j] += T;
        }
    }

    for(int i=1;i<=N+M;i++)
    {
        cout<<S[i]<<' ';
    }

    cout<<'\n';
    return  0;
}