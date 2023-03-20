#include    <iostream>

using namespace std;

static int  M,P,L,E,R,S,N;

#define INPUT_FORMAT    "%d %d %d %d %d %d %d"

int simulate(void)
{
    for(int i=1;i<=N;i++)
    {
        int num_of_new_imagoes = P/S;

        P = L/R;
        L = M*E;
        M = num_of_new_imagoes;
    }

    return  0;
}

int input(void)
{
    return  (scanf(INPUT_FORMAT,&M,&P,&L,&E,&R,&S,&N)!=EOF);
}

int main(void)
{
    for(;input();)
    {
        simulate();
        cout<<M<<'\n';
    }

    return  0;
}