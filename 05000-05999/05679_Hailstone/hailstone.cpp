#include    <iostream>

using namespace std;

#define is_even(n)  ((n)%2==0)

int simulate(int n)
{
    int ret = n;

    for(;n!=1;n=(is_even(n))?n>>1:3*n+1)
    {
        ret = max(ret,n);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int H;

        cin>>H;

        if( H == 0 )
        {
            break;
        }

        cout<<simulate(H)<<'\n';
    }

    return  0;
}