#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long int int64;

string simulate(void) {
    vector<string> exp;

    for (string s; cin >> s;) {
        if (s == "(") {
            exp.push_back(simulate());
        } else if (s == ")") {
            break;
        } else {
            exp.push_back(s);
        }
    }

    int64 result = 0;

    if (exp.front() == "-") {
        result = stoll(exp[1]) - stoll(exp[2]);
    } else if (exp.front() == "/") {
        result = stoll(exp[1]) / stoll(exp[2]);
    } else {
        for (int i = 1; i < exp.size(); i++) {
            result += stoll(exp[i]);
        }
    }

    return to_string(result);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    cin >> s;
    cout << simulate() << '\n';

    return 0;
}