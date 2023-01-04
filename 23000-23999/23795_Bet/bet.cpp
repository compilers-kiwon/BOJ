#include    <iostream>

using namespace std;

#define END_OF_INPUT    -1

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum = 0;

    for(;;)
    {
        int n;

        cin>>n;

        if( n == END_OF_INPUT )
        {
            break;
        }

        sum += n;
    }

    cout<<sum<<'\n';

    return  0;
}