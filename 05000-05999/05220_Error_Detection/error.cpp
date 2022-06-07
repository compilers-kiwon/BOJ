#include    <iostream>

using namespace std;

#define NUM_OF_BITS 16

int count_one_bits(int n)
{
    int ret = 0;

    for(int i=0;i<NUM_OF_BITS;i++)
    {
        if( (n&(1<<i)) != 0 )
        {
            ret++;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        int n,c;

        cin>>n>>c;

        if( (count_one_bits(n)+c)%2 == 0 )
        {
            cout<<"Valid\n";
        }
        else
        {
            cout<<"Corrupt\n";
        }
    }

    return  0;
}