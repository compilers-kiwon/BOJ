#include    <iostream>
#include    <string>

using namespace std;

typedef long long int   int64;

bool    is_palindrome(const string& num)
{
    for (int h=0,t=num.length()-1;h<t;h++,t--) {
        if (num[h] != num[t]) return false;
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   S,E;
    
    cin>>S>>E;

    for (;S<=E;S++) {
        string  num = to_string(S);
        cout<<(is_palindrome(num)?"Palindrome!":num)<<'\n';
    }

    return  0;
}