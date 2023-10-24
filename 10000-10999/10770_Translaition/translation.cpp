#include    <iostream>
#include    <string>

using namespace std;

const static string letters = "abcdefghijklmnopqrstuvwxyz";
const static string vowels = "aeiou";

static inline bool is_vowel(char c) {
    return  (vowels.find(c)!=string::npos);
}

static inline bool is_consonant(char c) {
    return  !is_vowel(c);
}

string  translate(const string& str) {
    string  ret;

    for (int i=0;i<str.length();i++) {
        ret.push_back(str[i]);
        if (is_vowel(str[i])) continue;

        int pos = letters.find(str[i]);

        for (int left=pos-1,right=pos+1;;left--,right++) {
            char left_chr = letters[max(0,left)];
            char right_chr = letters[min(right,(int)letters.length())];

            if (is_vowel(left_chr)) {
                ret.push_back(left_chr);
                break;
            }

            if (is_vowel(right_chr)) {
                ret.push_back(right_chr);
                break;
            }
        }

        if (str[i] == 'z') {
            ret.push_back('z');
            continue;
        }

        for (pos++;pos<letters.length();pos++) {
            if (is_consonant(letters[pos])) {
                ret.push_back(letters[pos]);
                break;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  s;

    cin>>s;
    cout<<translate(s)<<'\n';

    return  0;
}