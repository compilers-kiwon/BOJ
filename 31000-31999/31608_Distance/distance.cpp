#include <iostream>
#include <string>

using namespace std;

int get_num_of_diff(int len, const string& s1, const string& s2) {
    int ret = 0;

    for (int i = 0; i < len; i++) {
        ret += (s1[i]!=s2[i])?1:0;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S, T;

    cin >> N >> S >> T;
    cout << get_num_of_diff(N, S, T) << '\n';

    return 0;
}