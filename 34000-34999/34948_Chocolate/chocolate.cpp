#include <iostream>
#include <map>

using namespace std;

typedef long long int int64;

#define MAX_SIZE (200000+1)

int N, H[MAX_SIZE];
map<int64, int64> merged;

int64 input(void) {
    int64 total_width = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    for (int i = 1; i <= N; i++) {
        int64 W;
        cin >> W;
        merged[(int64)H[i]] += W, total_width += W;
    }

    return total_width;
}


int64 simulate(int64 total_width) {
    int64 max_area = 0LL;
    int64 prev_width = 0LL;

    for (auto it = merged.begin(); it != merged.end(); it++) {
        int64 cur_height = it->first;
        int64 cur_width = total_width - prev_width;

        max_area = max(max_area, cur_height * cur_width);
        prev_width += it->second;
    }

    return max_area;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 total_width = input();
    cout << simulate(total_width) << '\n';

    return 0;
}