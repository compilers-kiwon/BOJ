#include <iostream>
#include <string>

using namespace std;

bool is_correct(const string& str, int size) {
    int cnt_of_left = 0;

    for (int i = 0; i < size && cnt_of_left >= 0; ++i) {
        if (str[i] == '(') {
            ++cnt_of_left;
        } else {
            --cnt_of_left;
        }
    }

    return (cnt_of_left == 0);
}

bool dfs(string& str, int pos, int size) {
    if (pos == size) {
        return is_correct(str, size);
    }

    if (str[pos] == 'G') {
        str[pos] = '(';
        if (dfs(str, pos + 1, size) == true) {
            return true;
        }

        str[pos] = ')';
        if (dfs(str, pos + 1, size) == true) {
            return true;
        }

        str[pos] = 'G';
        return false;
    }

    return dfs(str, pos + 1, size);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string s;

    cin >> N >> s;
    dfs(s, 0, N);
    cout << s << '\n';

    return 0;
}