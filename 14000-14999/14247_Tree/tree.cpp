#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long int int64;
typedef pair<int, int> Tree; // <-grow, height>

void input(priority_queue<Tree>& pq) {
    int n;
    vector<int> height, grow;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int H;
        cin >> H;
        height.push_back(H);
    }

    for (int i = 0; i < n; i++) {
        int A;
        cin >> A;
        grow.push_back(A);
    }

    for (int i = 0; i < n; i++) {
        pq.push({-grow[i], height[i]});
    }
}

int64 simulate(priority_queue<Tree>& pq) {
    int64 ret = 0;

    for (int d = 0; !pq.empty(); pq.pop(), d++) {
        int grow = -pq.top().first * d;
        int height = pq.top().second;
        ret += (int64)(height + grow);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<Tree> t;

    input(t);
    cout << simulate(t) << '\n';

    return 0;
}