#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> State;

int simulate(priority_queue<State>& pq, int num_of_cuts) {
    int ret = 0;

    for (; !pq.empty();) {
        int cur = -pq.top().second;

        pq.pop();

        if (cur < 10) {
            continue;
        }

        if (cur == 10) {
            ++ret;
            continue;
        }

        if (num_of_cuts == 0) {
            break;
        }

        ++ret;
        --num_of_cuts;
    
        if ((cur - 10) >= 10) {
            pq.push({-((cur - 10) % 10), -(cur - 10)});
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    priority_queue<State> pq;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        pq.push({-(A % 10), -A});
    }

    cout << simulate(pq, M) << '\n';

    return 0;
}