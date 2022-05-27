#include    <iostream>

using namespace std;

int get_max_fuel(int f)
{
    int ret = 0;

    for(int i=0;;i++)
    {
        int f1 = i*i*i;

        if( f1 > f )
        {
            break;
        }

        for(int j=0;;j++)
        {
            int f2 = j*(j+1)*(j+2)/6;

            if( f1+f2 > f )
            {
                break;
            }

            ret = max(ret,f1+f2);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int n;

        cin>>n;

        if( n == 0 )
        {
            break;
        }

        cout<<get_max_fuel(n)<<'\n';
    }

    return  0;
}