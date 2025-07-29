#include <iostream>
#include <string>

using namespace std;

#define WIN_NUMBER_STR ("2023")

bool check_number(const string& num) {
    const string win = WIN_NUMBER_STR;
    size_t cur_pos = 0;

    for (int i = 0; i < win.length(); i++) {
        cur_pos = num.find(win[i], cur_pos);

        if (cur_pos == string::npos) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt;

    cnt = 0;
    cin >> N;

    for (int i = stoi(WIN_NUMBER_STR); i <= N; i++) {
        string s = to_string(i);

        if (check_number(s) == true) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}