#include <iostream>
#include <string>

using namespace std;

#define rainbow_ok (1<<0)
#define RAINBOW_OK (1<<1)

const string rainbow = "roygbiv";
const string RAINBOW = "ROYGBIV";
const string ans[] = {"NO!", "yes", "YES", "YeS"};

bool find_all_colors(const string& cur, const string& required) {
    for (int i = 0; i < required.length(); ++i) {
        if (cur.find(required[i]) == string::npos) {
            return false;
        }
    }

    return true;
}

int build_rainbow(const string& cur) {
    int ret = (find_all_colors(cur, rainbow)?rainbow_ok:0)
                + (find_all_colors(cur, RAINBOW)?RAINBOW_OK:0);
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S;

    cin >> N >> S;
    cout << ans[build_rainbow(S)] << '\n';

    return 0;
}