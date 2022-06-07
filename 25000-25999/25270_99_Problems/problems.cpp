#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,lower,upper;

    cin>>N;

    lower = 99;
    upper = 10099;

    for(int i=N;i>=lower;i--)
    {
        if( i%100 == 99 )
        {
            lower = i;
            break;
        }
    }

    for(int i=N;i<=upper;i++)
    {
        if( i%100 == 99 )
        {
            upper = i;
            break;
        }
    }

    if( N-lower < upper-N )
    {
        cout<<lower<<'\n';
    }
    else
    {
        cout<<upper<<'\n';
    }

    return  0;
}