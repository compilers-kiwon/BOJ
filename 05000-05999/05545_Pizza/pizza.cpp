#include <iostream>
#include <queue>

using namespace std;

typedef long long int int64;

int N;
int64 A, B, C;
priority_queue<int64> pq;

void input(void) {
    cin >> N >> A >> B >> C;

    for (int i = 1; i <= N; i++) {
        int64 D;
        cin >> D;
        pq.push(D);
    }
}

int64 simulate(void) {
    int64 cur_cal = C;
    int64 cur_price = A;

    for (; !pq.empty(); pq.pop()) {
        int64 new_cal = cur_cal + pq.top();
        int64 new_price = cur_price + B;

        if ((cur_cal * new_price) >= (cur_price * new_cal)) {
            break;
        }

        cur_cal = new_cal;
        cur_price = new_price;
    }

    return (cur_cal / cur_price);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}