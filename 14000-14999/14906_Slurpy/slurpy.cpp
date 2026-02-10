#include <iostream>
#include <string>

using namespace std;

bool is_slump(const string& str) {
    string expected = "DE";
    
    for (int cur_pos = 0; cur_pos < str.length(); ++cur_pos) {
        char c = str[cur_pos];

        if (expected.find(c) == string::npos) {
            return false;
        }

        if (expected == "DE") {
            expected = "F+";
        } else if (expected == "F+") {
            expected = "FDEG";
        } else if (expected == "FDEG") {
            switch (c) {
                case 'G': expected = ""; break;
                case 'D': case 'E': expected = "F+"; break;
                case 'F': default: /*do nothing*/; break;
            }
        }
    }

    return (expected == "");
}

bool is_slimp(const string& str) {
    if (str.front() != 'A') {
        return false;
    }

    if (str.length() == 2 && str.back() != 'H') {
        return false;
    }

    if (str.length() >= 3) {
        string mid1 = str.substr(2, str.length() - 3);
        string mid2 = str.substr(1, str.length() - 2);

        if ((str[1] != 'B' || mid1.empty() || is_slimp(mid1) != true || str.back() != 'C')
                && (mid2.empty() || is_slump(mid2) != true || str.back() != 'C')) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cout << "SLURPYS OUTPUT\n";

    for (cin >> N; N > 0; --N) {
        string str;
        bool parse_ok = false;

        cin >> str;

        for (int size = 1; size < str.length(); ++size) {
            string s1 = str.substr(0, size);
            string s2 = str.substr(size);

            if (is_slimp(s1) && is_slump(s2)) {
                parse_ok = true;
                break;
            }    
        }

        cout << (parse_ok?"YES":"NO") << '\n';
    }

    cout << "END OF OUTPUT\n";

    return 0;
}