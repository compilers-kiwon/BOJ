#include    <iostream>

using namespace std;

typedef unsigned long long  uint64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    uint64  D,P,N,R,Y;

    cin>>P>>N>>R;

    for(D=0,Y=N;N<=P;D++)
    {
        uint64  T = Y*R;

        N += T;
        Y = T;
    }

    cout<<D<<'\n';

    return  0;
}