#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

typedef long long int   int64;

#define chr2int(c)  ((int)((c)-'0'))

int64   get_decimal_from_skew(const string& s)
{
    int64   ret,b;

    ret = 0;
    b = pow(2,s.length());

    for (int i=0;i<s.length();i++,b>>=1) {
        ret += (int64)(s[i]-'0')*(b-1);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string  n;

        cin>>n;
        if (n == "0") break;
        cout<<get_decimal_from_skew(n)<<'\n';
    }

    return  0;
}