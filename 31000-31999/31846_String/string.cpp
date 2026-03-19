#include <iostream>

using namespace std;

#define MAX_SIZE (50+1)

int simulate(const char* str, int l, int r) {
    int ret = 0;

    for (int i = l; i < r; ++i) {
        int score = 0;

        for (int left = i, right = i + 1; left >= l && right <= r; --left, ++right) {
            if (str[left] == str[right]) {
                ++score;
            }
        }

        ret = max(ret, score);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, Q;
    char S[MAX_SIZE+1];

    cin >> N >> &S[1] >> Q;

    for (int i = 1; i <= Q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << simulate(S, l, r) << '\n';
    }

    return 0;
}