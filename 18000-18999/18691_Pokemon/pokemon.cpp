#include    <iostream>

using namespace std;

#define NUM_OF_GROUPS   3

const static int distance_to_get_candy[NUM_OF_GROUPS+1] = {0,1,3,5};

int simulate(int G,int C,int E)
{
    return  max(E-C,0)*distance_to_get_candy[G];
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int G,C,E;

        cin>>G>>C>>E;
        cout<<simulate(G,C,E)<<'\n';
    }

    return  0;
}