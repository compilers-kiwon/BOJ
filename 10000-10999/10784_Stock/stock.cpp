#include    <iostream>
#include    <cmath>
#include    <cfloat>

using namespace std;

#define get_price(p,a,b,c,d,k) \
    ((p)*(sin((a)*(k)+(b))+cos((c)*(k)+(d))+2))

int main(void)
{
    int     a,b,c,d,n;
    double  p,max_price,max_decline;

    cin>>p>>a>>b>>c>>d>>n;
    max_price = max_decline = DBL_MIN;

    for(int k=1;k<=n;k++)
    {
        double  cur_price = get_price(p,a,b,c,d,k);

        if( cur_price > max_price )
        {
            max_price = cur_price;
        }
        else
        {
            max_decline = 
                max(max_decline,max_price-cur_price);
        }
    }

    cout<<fixed;cout.precision(6);
    cout<<(max_decline==DBL_MIN?0:max_decline)<<'\n';
    
    return  0;
}