#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string target = "BRONZESILVER";

void input(vector<int>& cnt) {
    int N;
    string s;

    cin >> N >> s;

    for (int i = 0; i < N; ++i) {
        ++cnt[s[i]];
    }
}

int simulate(vector<int>& cnt) {
    int ret;

    for (ret = 0;; ++ret) {
        bool res = true;

        for (int i = 0; i < target.length(); ++i) {
            char required = target[i];

            if (cnt[required] == 0) {
                res = false;
                break;
            }

            --cnt[required];
        }

        if (res == false) {
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> cnt(0x100, 0);

    input(cnt);
    cout << simulate(cnt) << '\n';

    return 0;
}