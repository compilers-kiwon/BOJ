#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, K;
    priority_queue<int> pq;

    for (cin >> N >> M >> K; N > 0; N--) {
        int t;
        
        cin >> t;

        if (pq.size() == M) {
            int min_time = -pq.top();
            pq.pop();
            pq.push(-(t + min_time));
        } else {
            pq.push(-t);
        }
    }

    if (pq.size() < M || -pq.top() <= K) {
        cout << "WAIT\n";
    } else {
        cout << "GO\n";
    }

    return 0;
}