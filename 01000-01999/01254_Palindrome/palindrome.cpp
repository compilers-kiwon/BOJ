#include    <iostream>
#include    <string>

using namespace std;

static inline bool is_palindrome(const string& str) {
    for (int h=0,t=str.length()-1;h<t;h++,t--) {
        if (str[h] != str[t]) return false;
    }
    return  true;
}


int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  S;
    int length_of_sub_palindrome;

    cin>>S;

    for (int i=0;i<S.length();i++) {
        if (is_palindrome(S.substr(i))) {
            length_of_sub_palindrome = S.length()-i;
            break;
        }
    }
    
    cout<<S.length()*2-length_of_sub_palindrome<<'\n';
    return  0;
}