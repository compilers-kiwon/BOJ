#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_LENGTH (255)
#define MAX_ALLOWED_TRANSFORMATIONS (5000)

typedef pair<string, string> Rule;

void parse(const string& rule, string& from, string& to) {
    size_t pos = rule.find('=');
    from = rule.substr(0, pos), to = rule.substr(pos + 1);
}

string input(vector<Rule>& r) {
    int n;
    string ret;

    cin >> ret;

    for (cin >> n; n > 0; n--) {
        string ru, A, B;

        cin >> ru;
        parse(ru, A, B);
        r.push_back({A, B});
    }

    return ret;
}

bool transform(string& cur, const vector<Rule>& r) {
    for (int i = 0; i < r.size(); i++) {
        size_t pos = cur.find(r[i].first);

        if (pos != string::npos) {
            cur = cur.substr(0, pos) + r[i].second
                    + cur.substr(pos + r[i].first.length());
            return true;
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    vector<Rule> r;

    s = input(r);

    for (int i = 1;; i++) {
        if (transform(s, r) == false) {
            cout << s << '\n';
            return 0;
        } else {
            if (i > MAX_ALLOWED_TRANSFORMATIONS) {
                break;
            }
        }

        if (s.length() > MAX_LENGTH) {
            cout << "Memory Limit Exceeded\n";
            return 0;
        }
    }

    cout << "Time Limit Exceeded\n";

    return 0;
}