#include    <iostream>

using namespace std;

int simulate(int num)
{
    int ret = 0;

    for(int i=1;;i++)
    {
        if( num < i )
        {
            if( i%2 != 0 )
            {
                ret = i-num;
            }

            break;
        }

        num -= i;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    cout<<simulate(N)<<'\n';

    return  0;
}