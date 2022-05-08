#include    <iostream>

using namespace std;

int simulate(void)
{
    int ret,x,w;

    cin>>x>>w;

    if( x >= w )
    {
        return  0;
    }
    
    for(ret=1;;ret++)
    {
        x *= 2;

        if( x >= w )
        {
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int x;

    cin>>x;

    for(int i=1;i<=x;i++)
    {
        cout<<simulate()<<'\n';
    }

    return  0;
}