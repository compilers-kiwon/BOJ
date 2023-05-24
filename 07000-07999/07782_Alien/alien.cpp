#include    <iostream>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,b1,b2;

    cin>>n>>b1>>b2;

    for(int i=1;i<=n;i++)
    {
        int lx,ly,hx,hy;

        cin>>lx>>ly>>hx>>hy;

        if( IN_RANGE(lx,b1,hx) && IN_RANGE(ly,b2,hy) )
        {
            cout<<"Yes\n";
            return  0;
        }
    }

    cout<<"No\n";
    return  0;
}