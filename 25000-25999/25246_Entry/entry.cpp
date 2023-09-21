#include    <iostream>
#include    <string>

using namespace std;

const string vowels = "aeiou";

#define SUFFIX      "ntry"
#define is_vowel(c) (vowels.find((c))!=string::npos)

int get_last_vowel_pos(const string& str)
{
    int ret;

    for (int i=0;i<str.length();i++) {
        if (is_vowel(str[i])) ret=i;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  s;
    int     used_pos;

    cin>>s;
    used_pos = get_last_vowel_pos(s);

    cout<<s.substr(0,used_pos+1)<<SUFFIX<<'\n';
    return  0;
}