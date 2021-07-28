#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int n,m,b;

        cin>>n>>m;

        if( n==0 && m==0 )
        {
            break;
        }

        b = n-m;

        switch(b)
        {
            case    0:
            case    1:
                cout<<"0 0\n";
                break;
            case    3:
                cout<<"0 1\n";
                break;
            default:
                if( b%2 == 0 )
                {
                    cout<<b/2<<" 0\n";
                }
                else
                {
                    cout<<(b-3)/2<<" 1\n";
                }
                break;
        }
    }

    return  0;
}