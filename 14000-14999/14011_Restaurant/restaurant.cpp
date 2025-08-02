#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Challenge; // <-cost, award>

int simulate(priority_queue<Challenge>& pq, int money) {
    int ret = 0;

    for(; !pq.empty(); pq.pop()) {
        int cost = -pq.top().first;
        int award = pq.top().second;
        
        if (cost > money) {
            break;
        }

        money += award - cost;
        ret = max(ret, money);
    }

    return ((ret==0)?money:ret);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    vector<int> awards, costs;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        costs.push_back(c);
    }

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        awards.push_back(a);
    }

    priority_queue<Challenge> pq;

    for (int i = 0; i < N; i++) {
        if (costs[i] >= awards[i]) {
            continue;
        }

        pq.push({-costs[i], awards[i]});
    }

    cout << simulate(pq, M) << '\n';

    return 0;
}