#include <iostream>
#include <string>

using namespace std;

string get_tail_str(int idx) {
    string ret;

    if (idx < 26) {
        ret.push_back('A' + (char)idx);
    } else {
        idx -= 26;
        ret.push_back('a' + (char)(idx / 26));
        ret.push_back('a' + (char)(idx % 26));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;

    cin >> N >> M;
    cout << "SN " << N << get_tail_str(M - 1) << '\n';

    return 0;
}