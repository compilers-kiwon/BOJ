#include <iostream>
#include <string>

using namespace std;

int simulate(const string& exp, int pos, char expected) {
    if (pos == 0) {
        return ((exp[0]==expected)?0:1);
    }

    int ret;
    char var = exp[pos];
    char op = exp[pos-1];

    if (expected == 'T') {
        if (op == '|') {
            if (var == 'T') {
                ret = 0;
            } else {
                ret = min(simulate(exp, pos - 2, 'T'), 1);
            }
        } else {
            if (var == 'T') {
                ret = min(simulate(exp, pos - 2, 'T'), 1);
            } else {
                ret = min(simulate(exp, pos - 2, 'T') + 1, 2);
            }
        }
    } else {
        if (op == '|') {
            if (var == 'T') {
                ret = min(simulate(exp, pos - 2, 'F') + 1, 2);
            } else {
                ret = min(simulate(exp, pos - 2, 'F'), 1);
            }
        } else {
            if (var == 'T') {
                ret = min(simulate(exp, pos - 2, 'F'), 1);
            } else {
                ret = 0;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string exp;
    char result;

    for (cin >> N; N > 0; N--) {
        char c;
        cin >> c;
        exp.push_back(c);
    }

    cin >> result;
    cout << simulate(exp, exp.length() - 1, result) << '\n';

    return 0;
}