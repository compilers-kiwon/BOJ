#include <iostream>
#include <queue>

using namespace std;

typedef long long int int64;
typedef pair<int64, int64> Challenge; // <-cost, award>

int64 simulate(priority_queue<Challenge>& pq, int64 money) {
    int64 ret = 0;

    for(; !pq.empty(); pq.pop()) {
        int64 cost = -pq.top().first;
        int64 award = pq.top().second;
        
        if (cost > money) {
            break;
        }

        money += award - cost;
        ret = max(ret, money);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, M;
    vector<int64> awards, costs;

    cin >> N >> M;

    for (int64 i = 0; i < N; i++) {
        int64 c;
        cin >> c;
        costs.push_back(c);
    }

    for (int64 i = 0; i < N; i++) {
        int64 a;
        cin >> a;
        awards.push_back(a);
    }

    priority_queue<Challenge> pq;

    for (int64 i = 0; i < N; i++) {
        if (costs[i] >= awards[i]) {
            continue;
        }

        pq.push({ -costs[i], awards[i]});
    }

    cout << simulate(pq, M) << '\n';

    return 0;
}