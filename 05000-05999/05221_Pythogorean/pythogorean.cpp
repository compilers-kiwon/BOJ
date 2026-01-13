#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

typedef long long int int64;
typedef tuple<int64, int64, int64> Triple;

void input(vector<int64>& s, map<int64, int64>& p) {
    int n;

    for (cin >> n; n > 0; n--) {
        int64 num;
        cin >> num;
        s.push_back(num), p[num*num] = num;
    }

    sort(s.begin(), s.end());
}

void solve(const vector<int64>& s, map<int64, int64>& p, vector<Triple>& t) {
    for (int i = 0; i < s.size() - 2; i++) {
        for (int j = i + 1; j < s.size() - 1; j++) {
            auto it = p.find((s[i] * s[i]) + (s[j] * s[j]));

            if (it != p.end()) {
                t.push_back({s[i], s[j], it->second});
            }
        }
    }
}

void print_triples(const vector<Triple>& t) {
    cout << "Found Pythogorean triples:  ";

    vector<string> buf;

    for (int i = 0; i < t.size(); i++) {
        auto [a, b, c] = t[i];
        string s = "{" + to_string(a) + " " + to_string(b) + " " + to_string(c) + "}";
        buf.push_back(s);
    }

    sort(buf.begin(), buf.end());

    for (int i = 0; i < buf.size(); i++) {
        cout << buf[i] << ((i==buf.size()-1)?'\n':' ');
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; n--) {
        vector<int64> numbers;
        map<int64, int64> square;
        vector<Triple> tri;

        input(numbers, square);
        solve(numbers, square, tri);

        if (tri.empty()) {
            cout << "No Pythogorean triples found in the sequence.\n";
        } else {
            print_triples(tri);
        }
    }

    return 0;
}