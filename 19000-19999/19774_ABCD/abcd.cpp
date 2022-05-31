#include    <iostream>

using namespace std;

#define MOD(n)          ((n)%7)
#define is_password(n)  (MOD((n))==1)
#define get_upper(n)    ((n)/100)
#define get_lower(n)    ((n)%100)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        int n,lower,upper;

        cin>>n;

        lower = get_lower(n);
        upper = get_upper(n);

        if( is_password(upper*upper+lower*lower) == true )
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }

    return  0;
}