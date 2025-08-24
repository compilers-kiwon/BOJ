#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;
    int64 sum, prev;
    vector<int64> wine;

    cin >> N >> K;
    wine.push_back(0);

    for (int i = 1; i <= N; i++) {
        int64 T;
        cin >> T;
        wine.push_back(T);
    }

    sum = 0;
    sort(wine.begin(), wine.end());

    for (int h = 0, t = N, cur = 1; cur <= K; cur++) {
        if ((cur % 2) == 1) {
            sum += wine[t--] - wine[h];
        } else {
            h++;
        }
    }

    cout << sum << '\n';
    return 0;
}