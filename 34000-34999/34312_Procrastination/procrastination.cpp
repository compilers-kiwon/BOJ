#include <iostream>
#include <queue>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    priority_queue<pair<int, int64>> pq;

    for (cin >> N >> M; N > 0; N--) {
        int T, G;
        cin >> T >> G;
        pq.push({-T, G});
    }

    int64 sum = 0;

    for (;!pq.empty() && -pq.top().first <= M; pq.pop()) {
        M += pq.top().first, sum += pq.top().second;
    }

    cout << sum << '\n';
    
    return 0;
}