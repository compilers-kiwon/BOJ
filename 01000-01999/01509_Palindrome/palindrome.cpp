#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE (2500)

#define TBD (-1)
#define TRUE (1)
#define FALSE (0)

string str;
int dp[MAX_SIZE];
int palindrome[MAX_SIZE][MAX_SIZE];

bool is_palindrome(int h, int t) {
    if (h >= t) {
        return TRUE;
    }

    int& ret = palindrome[h][t];

    if (ret != TBD) {
        return ret;
    }

    if (str[h] == str[t]) {
        ret = is_palindrome(h + 1, t - 1);
    } else {
        ret = FALSE;
    }

    return ret;
}

int get_dp(int pos) {
    if (pos < 0) {
        return 0;
    }

    int& ret = dp[pos];

    if (ret != TBD) {
        return ret;
    }

    ret = MAX_SIZE;

    for (int h = pos; h >= 0; h--) {
        if (is_palindrome(h, pos) == TRUE) {
            ret = min(ret, get_dp(h - 1) + 1);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> str;
    fill(&palindrome[0][0],
         &palindrome[0][0] + (MAX_SIZE * MAX_SIZE),
         TBD);
    fill(&dp[0], &dp[0] + MAX_SIZE, TBD);

    cout << get_dp(str.length() - 1) << '\n';

    return 0;
}