#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

static inline char int2chr(int n) {
    return  (char)(n)+'0';
}

static inline int chr2int(char c) {
    return  (int)(c-'0');
}

string  add(const string& n1,const string& n2)
{
    int carry = 0;
    string  ret;

    for (int p1=n1.length()-1,p2=n2.length()-1;p1>=0||p2>=0;p1--,p2--) {
        char d1 = (p1>=0?n1[p1]:'0');
        char d2 = (p2>=0?n2[p2]:'0');
        int num = chr2int(d1)+chr2int(d2)+carry;

        ret.push_back(int2chr(num%10));
        carry = num/10;
    }

    if (carry != 0) ret.push_back('1');
    reverse(ret.begin(),ret.end());

    return  ret;
}

bool    is_cyclic(string s1,string s2)
{
    if (s1.length() != s2.length()) return  false;

    for (int i=0;i<s1.length();i++) {
        s1.push_back(s1.front());
        s1.erase(0,1);
        if (s1 == s2) return true;
    }

    return  false;
}

bool    simulate(const string& num)
{
    int num_of_adds = num.length();
    if (num_of_adds == 1) return true;

    string  cur = num;

    for (int i=2;i<=num_of_adds;i++) {
        cur = add(cur,num);
        if (!is_cyclic(cur,num)) return false;
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string  num;

        cin>>num;
        if (num.empty()) break;

        cout<<num<<" is "<<(simulate(num)?"":"not ")<<"cyclic\n";
    }

    return  0;
}