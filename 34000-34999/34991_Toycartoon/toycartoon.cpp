#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int max_length = 20;
const string base = "toycartoon";

bool find_TOY(const string& S, string& T, string& O, string& Y) {
    vector<string> ret;

    for (int size = S.length(); size > 0; --size) {
        size_t pos = base.find(S.substr(0, size));
        
        if (pos != string::npos) {
            T = base.substr(0, pos);
            O = base.substr(pos, size);
            Y = base.substr(pos + size);
            return true;
        }
    }

    return false;
}

string get_account_name(const string& S) {
    string ret, T, O, Y;

    if (find_TOY(S, T, O, Y) == false) {
        ret = base + "_" + S;
    } else {
        string tail = S.substr(O.length());
        
        ret = T + S + Y;

        for (int size = Y.length(); size > 0; --size) {
            string sub = Y.substr(0, size);

            if (sub.length() > tail.length()) {
                continue;
            }

            if (tail.substr(tail.length() - sub.length()) == sub) {
                Y.erase(0, size);
                ret = T + S + Y;
                break;
            }
        }
    }

    return ((ret.length()>max_length)?base:ret);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    cin >> S;
    cout << get_account_name(S) << '\n';

    return 0;
}