#include    <iostream>

using namespace std;

int     get_sum_of_digits(int n)
{
    int ret = 0;

    for(;n>0;n/=10)
    {
        ret += n%10;
    }

    return  ret;
}

bool    is_harshad_number(int n)
{
    return  ((n%get_sum_of_digits(n))==0);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(;;n++)
    {
        if( is_harshad_number(n) == true )
        {
            cout<<n<<'\n';
            break;
        }
    }

    return  0;
}