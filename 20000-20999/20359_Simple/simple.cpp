#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,o,p;

    cin>>n;

    for(p=0;;p++)
    {
        if( (n&(1<<p)) != 0 )
        {
            o = n>>p;
            break;
        } 
    }

    cout<<o<<' '<<p<<'\n';

    return  0;
}