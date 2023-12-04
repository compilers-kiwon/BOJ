#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

static inline char int2chr(int n) {
    return  (char)((int)'0'+n);
}

static inline int chr2int(char c) {
    return  (int)(c-'0');
}

static inline int get_digit(const string& num,int pos) {
    return  ((pos>=0)?chr2int(num[pos]):0);
}

string  add(const string& a,const string& b)
{
    string  sum;
    int carry = 0;

    for (int ptr_a=a.length()-1,ptr_b=b.length()-1;
            ptr_a>=0||ptr_b>=0;ptr_a--,ptr_b--) {
        int digit_a = get_digit(a,ptr_a);
        int digit_b = get_digit(b,ptr_b);
        int s = digit_a+digit_b+carry;

        sum.push_back(int2chr(s%10));
        carry = s/10;
    }

    if (carry != 0) sum.push_back(int2chr(carry));
    reverse(sum.begin(),sum.end());

    return  sum;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  a,b;

    cin>>a>>b;
    cout<<add(a,b)<<'\n';

    return  0;
}