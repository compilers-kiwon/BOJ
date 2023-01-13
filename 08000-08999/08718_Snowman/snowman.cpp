#include    <iostream>

using namespace std;

#define get_sum(a,b,c)      ((a)+(b)+(c))
#define convert_L_to_mL(n)  ((n)*1000)

#define make_snowman(used,total)    ((used)<=(total))

int main(void)
{
    int x,k,max_mL;

    cin>>x>>k;
    max_mL = 0;

    x = convert_L_to_mL(x);
    k = convert_L_to_mL(k);

    make_snowman(get_sum(k,k/2,k/4),x)?
        max_mL=max(max_mL,get_sum(k,k/2,k/4)):0;
    make_snowman(get_sum(k*2,k,k/2),x)?
        max_mL=max(max_mL,get_sum(k*2,k,k/2)):0;
    make_snowman(get_sum(k*4,k*2,k),x)?
        max_mL=max(max_mL,get_sum(k*4,k*2,k)):0;

    cout<<max_mL<<'\n';

    return  0;
}