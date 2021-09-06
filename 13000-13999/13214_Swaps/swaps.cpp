#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000000+1)

int N,A[MAX_SIZE],B[MAX_SIZE],pos[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    for(int i=1;i<=N;i++)
    {
        cin>>B[i];
        pos[B[i]] = i;
    }
}

int     simulate(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        if( A[i] == B[i] )
        {
            continue;
        }

        int p = pos[A[i]];
        int t = B[i];

        B[i] = B[p];
        B[p] = t;

        pos[t] = p;
        ret++;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}