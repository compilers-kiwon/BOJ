#include <iostream>

using namespace std;

#define MAX_SIZE (1000+1)

int max_val[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;

    for (cin >> N >> M; N > 0; N--) {
        for (int i = 1; i <= M; i++) {
            int G;
            cin >> G;
            max_val[i] = max(max_val[i], G);
        }
    }

    int sum = 0;

    for (int i = 1; i <= M; i++) {
        sum += max_val[i];
    }

    cout << sum << '\n';

    return 0;
}