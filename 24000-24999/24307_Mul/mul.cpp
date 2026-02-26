#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long int int64;

#define MAX_LEN (18)
#define chr2int(c) ((int)((c)-'0'))

int simulate(int64 num) {
    int cnt = 0;
    string s = to_string(num);

    for (; s.length() > 1; ++cnt) {
        int64 n = 1LL;

        for (int i = 0; i < s.length(); ++i) {
            n *= (int64)chr2int(s[i]);
        }

        s = to_string(n);
    }

    return cnt;
}

int64 bfs(int num_of_operations) {
    if (num_of_operations == 0) {
        return 0LL;
    }

    if (num_of_operations == 1) {
        return 10LL;
    }

    int64 ret;
    queue<int64> q;

    for (int64 i = 2LL; i <= 9LL; ++i) {
        q.push(i);
    }

    for (; !q.empty(); q.pop()) {
        int64 cur_num = q.front();

        if (to_string(cur_num).length() > MAX_LEN) {
            continue;
        }

        int n = simulate(cur_num);

        if (n >= num_of_operations) {
            if (n == num_of_operations) {
                ret = cur_num;
                break;
            }

            continue;
        }

        for (int64 d = cur_num % 10; d <= 9LL; ++d) {
            if (d >= 2LL) {
                q.push((cur_num * 10LL) + d);
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int P;
    cin >> P;
    cout << bfs(P) << '\n';

    return 0;
}