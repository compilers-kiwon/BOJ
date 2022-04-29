#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,p,q;

    cin>>n>>p>>q;

    for(int i=1;i<=n;i++)
    {
        int current;

        cin>>current;

        if( p == current )
        {
            continue;
        }

        if( current > q )
        {
            cout<<"BBTV: Dollar reached "<<current<<" Oshloobs, A record!\n";
            q = current;
        }
        else
        {
            if( current < p )
            {
                cout<<"NTV: Dollar dropped by "<<p-current<<" Oshloobs\n";
            }
        }

        p = current;
    }

    return  0;
}