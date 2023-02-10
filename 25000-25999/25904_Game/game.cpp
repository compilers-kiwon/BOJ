#include    <iostream>

using namespace std;

#define MAX_SIZE    100

static int  N,X,T[MAX_SIZE];

int simulate(void)
{
    int ret;

    for(int i=0;;i=(i+1)%N,X++)
    {
        if( X > T[i] )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int input(void)
{
    cin>>N>>X;

    for(int i=0;i<N;i++)
    {
        cin>>T[i];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()+1<<'\n';

    return  0;
}