#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, sum;

    cin >> N >> M, sum = 0;

    for (int i = 1; i <= N; i++) {
        int s, e;
        cin >> s >> e;
    }

    for (int i = 1; i <= M; i++) {
        int t, p;
        cin >> t >> p;
        sum += p;
    }

    cout << fixed; cout.precision(4);
    cout << (double)sum / (double)N << '\n';

    return 0;
}