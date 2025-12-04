#include <iostream>

using namespace std;

typedef long long int int64;

const int64 DIGIT_NUM = 8LL;

bool dfs(int64 cur_num, int64 carry, int64 prev_num_of_used) {
    if (cur_num == 0) {
        return (carry == 0LL);
    }

    int64 tail = cur_num % 10LL;

    for (int64 i = 0LL; i <= prev_num_of_used; i++) {
        int64 n = (DIGIT_NUM * i) + carry;

        if ((n % 10) == tail && dfs(cur_num / 10LL, n / 10LL, i) == true) {
            return true;
        }
        
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        int64 N;
        cin >> N;
        cout << (dfs(N, 0LL, DIGIT_NUM)?"Yes":"No") << '\n';
    }

    return 0;
}