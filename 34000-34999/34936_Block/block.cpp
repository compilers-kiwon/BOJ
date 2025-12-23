#include <iostream>
#include <queue>

using namespace std;

typedef long long int int64;
typedef pair<int64, int64> Tr;  // <cost, -time>

int64 generate_block(priority_queue<Tr>& pq,
                    int num_of_trs, int64 min_time) {
    int64 ret = 0;

    for (; !pq.empty() && num_of_trs > 0; pq.pop()) {
        int64 cost = pq.top().first;
        int64 time = -pq.top().second;

        if (time < min_time) {
            continue;
        }

        ret += cost, num_of_trs--;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;
    int64 T, sum;
    priority_queue<Tr> pq;

    for (cin >> N >> T >> K, sum = 0; N > 0; N--) {
        int64 op, t, f;

        cin >> op;

        if (op == 1LL) {
            cin >> t >> f;
            pq.push({f, -t});
        } else {
            cin >> t;
            sum += generate_block(pq, K, t - T);
        }
    }

    cout << sum << '\n';
    
    return 0;
}