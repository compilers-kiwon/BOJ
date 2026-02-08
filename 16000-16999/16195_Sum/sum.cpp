#include <iostream>
#include <vector>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (1000)
#define MOD(n) ((n)%1000000009)

int dp[MAX_SIZE+1][MAX_SIZE+1];

int get_dp(int num, int cnt,
            const vector<int>& available) {
    if (num == 0) {
        return 1;
    }

    if (cnt == 0) {
        return 0;
    }

    int& ret = dp[num][cnt];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int i = 0; i < available.size(); ++i) {
        if (num - available[i] >= 0) {
            ret = MOD(ret + get_dp(num - available[i], cnt - 1, available));
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    fill(&dp[0][0], &dp[0][0] + ((MAX_SIZE + 1) * (MAX_SIZE + 1)), TBD);

    vector<int> num = {1, 2, 3};

    for (int i = 0; i < num.size(); ++i) {
        dp[num[i]][1] = 1;
    }
    
    for (int row = MAX_SIZE; row >= 1; --row) {
        for (int col = MAX_SIZE; col >= 1; --col) {
            get_dp(row, col, num);
        }
    }

    int T;

    for (cin >> T; T > 0; --T) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }

    return 0;
}