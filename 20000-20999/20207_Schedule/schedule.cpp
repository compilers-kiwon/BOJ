#include <iostream>

using namespace std;

#define MAX_SIZE (365)

int cnt[MAX_SIZE+2];

void input(void) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int S, E;

        for (cin >> S >> E; S <= E; ++S) {
            ++cnt[S];
        }
    }
}

int simulate(void) {
    int ret, width, height;

    ret = width = height = 0;

    for (int i = 1; i <= (MAX_SIZE + 1); ++i) {
        if (cnt[i] == 0) {
            ret += width * height;
            width = height = 0;
        } else {
            ++width, height = max(height, cnt[i]);
        }
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