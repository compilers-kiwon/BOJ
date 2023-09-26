#include    <iostream>
#include    <string>

using namespace std;

const static string vowels = "aeiou";

#define is_vowel(c) (vowels.find((c))!=string::npos)

bool    is_palindrome(string str)
{
    for (int h=0,t=str.length()-1;h<t;h++,t--) {
        if (str[h] != str[t]) return false;
    }

    return  true;
}

string  get_vowels(string str)
{
    string  ret;

    for (int i=0;i<str.length();i++) {
        if (is_vowel(str[i])) ret.push_back(str[i]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    cin>>str;
    cout<<(is_palindrome(get_vowels(str))?"S":"N")<<'\n';

    return  0;
}