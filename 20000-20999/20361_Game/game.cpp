#include    <iostream>
#include    <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             N,X,K;
    vector<bool>    cup;

    cin>>N>>X>>K;

    // 1. initialize
    cup.resize(N+1,false);
    cup[X] = true;

    // 2. Simulate
    for(int i=1;i<=K;i++)
    {
        int     A,B;
        bool    tmp;
        
        cin>>A>>B;
        tmp=cup[A];cup[A]=cup[B];cup[B]=tmp;
        
        
    }

    // 3. Find a ball
    for(int i=1;i<=N;i++)
    {
        if( cup[i] == true )
        {
            cout<<i<<'\n';
            break;
        }
    }

    return  0;
}