#include    <iostream>

using namespace std;

#define MAX_NUM_OF_VOLUNTEERS   (10000+1)

static bool returned[MAX_NUM_OF_VOLUNTEERS];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,R;

    cin>>N>>R;

    if( N == R )
    {
        cout<<"*\n";
        return  0;
    }

    for(int i=1;i<=R;i++)
    {
        int r;

        cin>>r;
        returned[r] = true;
    }

    for(int i=1;i<=N;i++)
    {
        if( returned[i] == false )
        {
            cout<<i<<' ';
        }
    }

    cout<<'\n';
    return  0;
}