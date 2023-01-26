#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,P,min_price;

    cin>>N>>P;
    min_price = P;

    if( N >= 5 )
    {
        min_price = min(P-500,min_price);
    }

    if( N >= 10 )
    {
        min_price = min(P/100*90,min_price);
    }

    if( N >= 15 )
    {
        min_price = min(P-2000,min_price);
    }

    if( N >= 20 )
    {
        min_price = min(P/100*75,min_price);
    }

    cout<<max(min_price,0)<<'\n';

    return  0;
}