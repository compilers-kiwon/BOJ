#include <iostream>
#include <queue>

using namespace std;

#define IN (1)
#define OUT (-1)

typedef pair<double, int> State;

void input(priority_queue<State>& pq) {
    int n;

    for (cin >> n; n > 0; n--) {
        double x, a, b, low, high;
        
        cin >> x >> a >> b;
        low = a / x, high = b / x;
        pq.push({-low, IN}), pq.push({-high, OUT});
    }
}

int simulate(priority_queue<State>& pq) {
    int ret = 0;

    for (int cnt = 0; !pq.empty(); pq.pop()) {
        cnt += pq.top().second;
        ret = max(ret, cnt);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<State> pq;
    
    input(pq);
    cout << simulate(pq) << '\n';

    return 0;
}