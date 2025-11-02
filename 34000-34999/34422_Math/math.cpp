#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> exp;

    for (string s; cin >> s;) {
        if (!exp.empty() && (exp.back() == "+" || exp.back() == "-")) {
            int n1, n2, result;
            string op = exp.back();

            exp.pop_back();
            n1 = stoi(exp.back()), n2 = stoi(s);
            exp.pop_back();

            if (op == "+") {
                result = n1 + n2;
            } else {
                result = n1 - n2;
            }

            exp.push_back(to_string(result));
        } else {
            exp.push_back(s);
        }
    }

    for (int i = 1; i < exp.size(); i += 2) {
        float n1 = stof(exp[i-1]);
        float n2 = stof(exp[i+1]);

        if (exp[i] == "*") {
            exp[i+1] = to_string(n1 * n2);
        } else {
            exp[i+1] = to_string(n1 / n2);
        }
    }

    cout << (int)floor(stof(exp.back())) << '\n';
    return 0;
}