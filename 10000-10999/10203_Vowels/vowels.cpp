#include <iostream>
#include <string>

using namespace std;

const string vowels = "aeiou";

int vowel_val[0x100];

void init(void) {
    for (int i = 0; i < vowels.length(); i++) {
        vowel_val[vowels[i]] = 1;
    }
}

int count_vowels(const string& s) {
    int ret = 0;

    for (int i = 0; i < s.length(); i++) {
        ret += vowel_val[s[i]];
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N, init(); N > 0; N--) {
        string w;
        cin >> w;
        cout << "The number of vowels in " << w
                << " is " << count_vowels(w) << ".\n";
    }

    return 0;
}