#include    <iostream>
#include    <string>

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

int get_weight(int n)
{
    return  to_string(n).length()
                *get_sum_of_digits(n);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n1,n2,w1,w2;

    cin>>n1>>n2;

    w1 = get_weight(n1);
    w2 = get_weight(n2);

    cout<<(w1==w2?0:w1>w2?1:2)<<'\n';

    return  0;
}