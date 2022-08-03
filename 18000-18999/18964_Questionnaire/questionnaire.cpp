#include    <iostream>

using namespace std;

int main(void)
{
    int n,num_of_odd,num_of_even;

    cin>>n;
    num_of_odd = num_of_even = 0;

    for(int i=1;i<=n;i++)
    {
        int a;

        cin>>a;

        if( a%2 == 0 )
        {
            num_of_even++;
        }
        else
        {
            num_of_odd++;
        }
    }

    if( num_of_even >= num_of_odd )
    {
        cout<<"2 0\n";
    }
    else
    {
        cout<<"2 1\n";
    }

    return  0;
}