#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

static int  N,M,K,A[MAX_SIZE][MAX_SIZE];

int simulate(void)
{
    int length[MAX_SIZE] = {0,};

    for(int q=1;q<=M;q++)
    {
        for(int p=1;p<=N;p++)
        {
            length[p] += A[p][q];

            if( length[p] >= K )
            {
                cout<<p<<' ';
                return  q;
            }
        }
    }

    return  0;
}

int input(void)
{
    cin>>N>>M>>K;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>A[row][col];
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}