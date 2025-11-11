#include <iostream>
#include <string>

using namespace std;

#define chr2int(c) ((int)((c)-'0'))

string solve(string num) {
    if (num.length() == 1) {
        return num;
    }

    int output = 0;

    for (int i = 0; i < num.length(); i++) {
        output += chr2int(num[i]);
    }

    return solve(to_string(output));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string C;
    cin >> C;
    cout << solve(C) << '\n';

    return 0;
}