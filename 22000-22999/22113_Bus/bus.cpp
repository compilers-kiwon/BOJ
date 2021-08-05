#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int N,M,bus[MAX_SIZE],A[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        cin>>bus[i];
    }

    for(int S=1;S<=N;S++)
    {
        for(int E=1;E<=N;E++)
        {
            cin>>A[S][E];
        }
    }
}

int     simulate(void)
{
    int ret = 0;

    for(int b=1;b<M;b++)
    {
        ret += A[bus[b]][bus[b+1]];
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