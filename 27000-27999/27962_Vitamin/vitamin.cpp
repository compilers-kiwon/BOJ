#include <iostream>
#include <string>

using namespace std;

#define ALLOWED_NUM_OF_DIFFS (1)

bool compare_str(const string& s1, const string& s2, int num, int size) {
    int cnt = 0;

    for (int i = 0; i < size; ++i) {
        if ((cnt += (s1[i]!=s2[i]?1:0)) > num) {
            return false;
        }
    }

    return (cnt == num);
}

bool simulate(const string& str, int length) {
    for (int size = 1, t = length - 1;
                size < length; ++size, --t) {
        string s1 = str.substr(0, size);
        string s2 = str.substr(t);

        if (compare_str(s1, s2, ALLOWED_NUM_OF_DIFFS, size) == true) {
            return true;
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string s;

    cin >> N >> s;
    cout << (simulate(s, N)?"YES":"NO") << '\n';

    return 0;
}