#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string& s) {
    for (size_t head = 0, tail = s.length() - 1;
            head < tail; head++, tail--) {
        if (s[head] != s[tail]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    
    cin>>s;
    cout<<(is_palindrome(s)?"beep":"boop")<<'\n';

    return 0;
}