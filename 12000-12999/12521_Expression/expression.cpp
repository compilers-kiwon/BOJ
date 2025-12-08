#include <iostream>
#include <string>

using namespace std;

const string vowel = "aeiou";

int get_num_of_syllable(const string& str) {
    int ret = 0;
    
    for (int i = 0; i < str.length(); i++) {
        ret += (vowel.find(str[i])!=string::npos)?1:0;
    }

    return ret;
}

bool is_spell(const string& str) {
    if (str.length() < 5) {
        return false;
    }

    for (int length = 1; length <= (str.length() / 2); length++) {
        string start = str.substr(0, length);
        string middle = str.substr(length, str.length() - (2 * length));
        string end = str.substr(str.length() - length, length);

        if (middle.empty()) {
            return false;
        }

        if (start != end) {
            continue;
        }

        if (get_num_of_syllable(start) >= 2 &&
                get_num_of_syllable(middle) >= 1) {
            return true;
        }
    }

    return false;
}

bool simulate(const string& str) {
    for (int i = 0; i < str.length(); i++) {
        string sub;

        for (int j = i ; j < str.length(); j++) {
            sub.push_back(str[j]);

            if (is_spell(sub) == true) {
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        string exp;
        cin >> exp;
        cout << "Case #" << t << ": " <<
                (simulate(exp)?"Spell!":"Nothing.") << '\n';
    }

    return 0;
}