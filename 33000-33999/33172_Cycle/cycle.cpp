#include <iostream>
#include <string>

using namespace std;

bool is_cycle(const string& full, const string& sub) {
    string str;
    for (; str.length() < full.length(); str += sub);
    return (str == full);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S;
    bool result;

    cin >> N >> S;
    result = false;

    for (int sub_len = N / 2; sub_len >= 1; sub_len--) {
        if ((N % sub_len) != 0) {
            continue;
        }

        string sub = S.substr(0, sub_len);

        if (is_cycle(S, sub) == true) {
            result = true;
            break;
        }
    }

    cout << (result?"Yes":"No") << '\n';
    return 0;
}