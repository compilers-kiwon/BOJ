#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,two,three;

    cin>>n;

    for(two=0;two*2<=n;two++)
    {
        if( (n-two*2)%3 == 0 )
        {
            three = (n-two*2)/3;
            break;
        }
    }

    cout<<two<<' '<<three<<'\n';

    return  0;
}