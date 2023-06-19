#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

static int  N,K,B,X[MAX_SIZE];

int input(void)
{
    cin>>N>>K>>B;

    for(int i=1;i<=N;i++)
    {
        cin>>X[i];
    }

    return  0;
}

int simulate(void)
{
    int ret = 0;

    for(int s=B-(B/N)*N,i=1;i<=K;i++,s++)
    {
        s = (s>N||s<1)?1:s;
        ret += X[s];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}