#include <iostream>
#include <string>

using namespace std;

const string TARGET = "PAUL";

#define TBD (-1)
#define TRUE (1)
#define FALSE (0)

#define MAX_SIZE (100000)

int N, dp[MAX_SIZE];
string str;

int get_dp(int found_pos, int cur_pos) {
    if (found_pos == 0) {
        return (cur_pos%2==0)?TRUE:FALSE;
    }

    int& ret = dp[cur_pos];

    if (ret != TBD) {
        return ret;
    }

    ret = FALSE;

    for (int i = cur_pos - 1; i >= 0; i -= 2) {
        if (str[i] == TARGET[found_pos-1]
                && get_dp(found_pos - 1, i)) {
            ret = TRUE;
            break;
        }
    }

    return ret;
}

void input(void) {
    cin >> N >> str;
    fill(dp, dp + N, TBD);
}

string simulate(void) {
    for (int i = N - 1, tail = 0; i >= 0; i--, tail++) {
        if (str[i] == TARGET.back() && (tail % 2) == 0) {
            if (get_dp(TARGET.length() - 1, i) == TRUE) {
                return "YES";
            }
        }
    }

    return "NO";
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}