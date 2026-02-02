#include <iostream>
#include <string>

using namespace std;

#define chr2int(c) ((int)((c)-'0'))

void input(string& exp) {
    int X;

    cin >> X;

    for (int i = 1; i <= 2*X + 1; ++i) {
        char c;
        cin >> c;
        exp.push_back(c);
    }
}

char calculate(const string& exp) {
    if (exp.find('!') != string::npos) {
        return '!';
    }

    int sum = 0;

    for (int i = 0; i < exp.length(); i += 2) {
        sum += chr2int(exp[i]);
    }

    return ((sum>9)?'!':to_string(sum).front());
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; --N) {
        string exp;
        input(exp);
        cout << calculate(exp) << '\n';
    }

    return 0;
}