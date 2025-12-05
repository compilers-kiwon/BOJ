#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE (5000+1)
#define MAX_PRICE (10000+1)

typedef pair<int, int> Candy; // <cal, price>

int n, m, dp[MAX_PRICE];
Candy attr[MAX_SIZE];

int read_float(void) {
    string str;
    cin >> str;
    return ((stoi(str.substr(0, str.find('.'))) * 100)
                + (stoi(str.substr(str.find('.') + 1))));
}

bool input(void) {
    cin >> n;
    m = read_float();

    if (n == 0 && m == 0) {
        return false;
    }

    for (int i = 1; i <= n; i++) {
        cin >> attr[i].first;
        attr[i].second = read_float();
    }

    return true;
}

int simulate(void) {
    int ret = 0;

    for (int i = 1; i <= n; i++) {
        int cur_cal = attr[i].first;
        int cur_price = attr[i].second;

        for (int p = cur_price; p <= m; p++) {
            dp[p] = max(dp[p], dp[p-cur_price] + cur_cal);
        }
    }

    for (int i = 1; i <= m; i++) {
        ret = max(ret, dp[i]);
    }
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;input();) {
        fill(&dp[1], &dp[m+1], 0);
        cout << simulate() << '\n';
    }

    return 0;
}