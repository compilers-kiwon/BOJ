#include    <iostream>

using namespace std;

string  get_message(int t1,int v1,int t2,int v2)
{
    if( t2<0 && v2>=10 )
    {
        return  "A storm warning for tomorrow! "
                    "Be careful and stay home if possible!";
    }

    if( t2 < t1 )
    {
        return  "MCHS warns! Low temperature"
                    " is expected tomorrow.";
    }

    if( v2 > v1 )
    {
        return  "MCHS warns! Strong wind"
                    " is expected tomorrow.";
    }

    return  "No message";
}

int     main(void)
{
    int t1,v1,t2,v2;

    cin>>t1>>v1>>t2>>v2;
    cout<<get_message(t1,v1,t2,v2)<<'\n';

    return  0;
}