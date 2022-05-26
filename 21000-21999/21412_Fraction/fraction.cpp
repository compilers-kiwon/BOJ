#include    <iostream>

using namespace std;

bool    find_common_divisor(int a,int b)
{
    bool    ret = false;

    for(int i=2;i<=min(a,b);i++)
    {
        if( a%i==0 && b%i==0 )
        {
            ret = true;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,a,b;
    double  max_fraction;

    cin>>n;
    max_fraction = 0.0;

    for(int i=1;i<=n/2;i++)
    {
        if( find_common_divisor(i,n-i) == true )
        {
            continue;
        }

        double  f = (double)i/(double)(n-i);

        if( f > max_fraction )
        {
            max_fraction = f;
            a = i;
            b = n-i;
        }
    }

    cout<<a<<' '<<b<<'\n';

    return  0;
}