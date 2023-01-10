#include    <iostream>

using namespace std;

int get_sum_of_digits(int n)
{
    int ret = 0;

    for(;n>0;n/=10)
    {
        ret += n%10;
    }

    return  ret;
}

int play_game(int n)
{
    if( n < 10 )
    {
        return  n;
    }

    return  play_game(get_sum_of_digits(n));
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int N;

        cin>>N;
        
        if( N == 0 )
        {
            break;
        }

        cout<<play_game(N)<<'\n';
    }

    return  0;
}