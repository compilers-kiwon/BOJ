#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;

#define NUM_OF_SUITS (5)

void parse(const string& buf, vector<int>& num) {
    string cur;

    for (int i = 0; i < buf.length(); i++) {
        if (buf[i] == ' ') {
            num.push_back(stoi(cur));
            cur.clear();
        } else {
            cur.push_back(buf[i]);
        }
    }
}

bool input(vector<int>& num) {
    string s;
    vector<int> data;
    set<int> suits;

    getline(cin, s);
    if (isdigit(s.back())) {s.push_back(' ');}
    parse(s, data);

    for (int i = 0; i < data.size(); i += 2) {
        suits.insert(data[i]), num.push_back(data[i+1]);
    }

    return (suits.size() == NUM_OF_SUITS);
}

bool is_spread(const vector<int>& num) {
    set<int> diff;

    for (int i = 0; i < num.size(); i++) {
        for (int j = i + 1; j < num.size(); j++) {
            int d = abs(num[i] - num[j]);

            if (diff.find(d) != diff.end()) {
                return false;
            }

            diff.insert(d);
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string in;

    getline(cin, in);

    for (int t = stoi(in); t > 0; t--) {
        bool rainbow;
        vector<int> card_values;

        rainbow = input(card_values);

        if (is_spread(card_values) == true) {
            cout << "Have a spread.          ";
        } else {
            cout << "Do not have a spread.   ";
        }

        cout << (rainbow?"Have a rainbow.":"Do not have a rainbow.") << '\n';
    }

    return 0;
}