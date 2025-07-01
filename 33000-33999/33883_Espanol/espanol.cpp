#include <iostream>
#include <string>

using namespace std;

const string vowel = "aeiou";

int get_accent_pos(const string& s) {
    char last = s.back();

    if (vowel.find(last) == string::npos
            && (last != 'n' && last != 's')) {
        return 1;
    }

    return 2;
}

int mark_accent(int accent_pos, const string& s) {
    int ret = -1;
    int num_of_vowels = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (vowel.find(s[i]) != string::npos
                && ++num_of_vowels == accent_pos) {
            ret = i + 1;
            break;
        }
    }

    return ret;
}

int main(void) {
    string S;

    cin>>S;
    cout<<mark_accent(get_accent_pos(S), S)<<'\n';

    return 0;
}