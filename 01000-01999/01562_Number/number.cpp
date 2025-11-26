#include <iostream>
#include <string>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (100+1)
#define MAX_NUM (9)
#define ALL_NUMBERS (1024-1)
#define MOD(n) ((n)%1000000000)

int N, dp[MAX_SIZE][MAX_NUM+1][ALL_NUMBERS+1];

int get_dp(int pos, int num, int used) {
    if (pos == 1) {
        return (((used != ALL_NUMBERS) || (num == 0))?0:1);
    }

    int& ret = dp[pos][num][used];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    // +1
    if (num != 9) {
        ret = MOD(ret + get_dp(pos - 1, num + 1, used | (1 << (num + 1))));
    }

    // -1
    if (num != 0) {
        ret = MOD(ret + get_dp(pos - 1, num - 1, used | (1 << (num - 1))));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, sum;

    cin >> N, sum = 0;

    for (int row = 0; row < MAX_SIZE; row++) {
        for (int col = 0; col < (MAX_NUM + 1); col++) {
            fill(&dp[row][col][0], &dp[row][col][ALL_NUMBERS+1], TBD);
        }
    }
    
    for (int s = 0; s <= 9; s++) {
        sum = MOD(sum + get_dp(N, s, 1 << s));
    }
    
    cout << sum << '\n';
    return 0;
}