#include <iostream>
#include <deque>

using namespace std;

#define MAX_SIZE (100000+2)

typedef long long int int64;

typedef pair<int, int> State;

int N, H[MAX_SIZE];
deque<State> histo;

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> H[i];
    }

    H[++N] = 0;
}

int64 simulate(void) {
    int64 ret = 0LL;

    for (int i = 1; i <= N; ++i) {
        if (histo.empty() || histo.back().first <= H[i]) {
            histo.push_back({H[i], i});
            continue;
        }

        int start_idx;

        for (; !histo.empty(); histo.pop_back()) {
            int64 cur_height = (int64)histo.back().first;
            int64 cur_width = (int64)(i - histo.back().second);

            if (H[i] > cur_height) {
                break;
            }

            ret = max(ret, cur_height * cur_width);
            start_idx = histo.back().second;
        }

        histo.push_back({H[i], start_idx});
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}