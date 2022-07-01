#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=0;i<=31;i++)
    {
        if( (n&(1<<i)) != 0 )
        {
            cout<<i<<' ';
        }
    }

    return  0;
}