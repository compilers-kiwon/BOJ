#include    <iostream>

using namespace std;

#define MSB_POS 15

typedef long long int   int64;

#define add_one_bit(m,n,p)  {(m)<<=1;(m)+=(1&((n)>>(p)));}

int main(void)
{
    int64   x,y,morton;

    cin>>x>>y;
    morton = 0;

    for (int pos=MSB_POS;pos>=0;pos--) {
        add_one_bit(morton,x,pos);
        add_one_bit(morton,y,pos);
    }

    cout<<morton<<'\n';
    return  0;
}