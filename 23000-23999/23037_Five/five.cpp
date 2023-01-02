#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

#define EXPONENT    5
#define chr2int(c)  ((int)((c)-'0'))

int get_sum(const string& num)
{
    int ret = 0;

    for(int i=0;i<num.length();i++)
    {
        ret += pow(chr2int(num[i]),EXPONENT);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  n;

    cin>>n;
    cout<<get_sum(n)<<'\n';

    return  0;
}