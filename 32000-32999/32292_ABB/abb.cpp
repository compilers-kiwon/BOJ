#include <iostream>
#include <string>
#include <deque>

using namespace std;

void input(deque<char>& in) {
    int n;
    string S;

    cin >> n >> S;

    for (int i = 0; i < n; ++i) {
        in.push_back(S[i]);
    }
}

void simulate(string& result, deque<char>& in) {
    while (!in.empty()) {
        char c = in.front();
        result.push_back(c), in.pop_front();

        if (result.length() < 3) {
            continue;
        }

        int idx = result.length() - 3;

        if (result[idx] == 'A' && result[idx+1] == 'B' && result[idx+2] == 'B') {
            in.push_front('A');
            in.push_front('B');
            result.erase(idx);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; --t) {
        string s;
        deque<char> in;

        input(in);
        simulate(s, in);
        cout << s << '\n';
    }

    return 0;
}