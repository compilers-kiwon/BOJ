#include    <iostream>

using namespace std;

#define MAX_SIZE    (200000+1)

static int  N,M,V,C[MAX_SIZE],K[MAX_SIZE];

#define steps_in_cycle(to,cycle_begin,cycle_size) \
        (((to)-(cycle_begin))%(cycle_size)+(cycle_begin))

int input(void)
{
    cin>>N>>M>>V;

    for(int i=1;i<=N;i++)
    {
        cin>>C[i];
    }

    for(int i=1;i<=M;i++)
    {
        cin>>K[i];
    }

    return  0;
}

int check_query(void)
{
    int s = (N-V)+1;

    for(int i=1;i<=M;i++)
    {
        int idx = 1+K[i];

        if( idx <= N )
        {
            cout<<C[idx]<<'\n';
        }
        else
        {
            cout<<C[steps_in_cycle(idx,V,s)]<<'\n';
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    check_query();

    return  0;
}