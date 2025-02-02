#include <iostream>
#include <queue>

using namespace std;

const int A_price = 5000;
const int B_price = 1000;

int N, X;
priority_queue<int> pq;

// Until we have enough money, we move to the other menu whose
// level difference is the highest. If the difference is equal
// to or less than 0, we don't need to move.
int upgrade_menu(int cur_level) {
    int ret = cur_level;
    int cur_money = X - (N * B_price);

    for (;!pq.empty() && cur_money >= (A_price - B_price); pq.pop()) {
        if (pq.top() <= 0) {
            break;
        }

        ret += pq.top();
        cur_money -= A_price - B_price;
    }

    return ret;
}

// By default, assume that we select a cheaper menu.
// Keep a difference between A and B.
int input(void) {
    int ret = 0;

    cin>>N>>X;

    for (int i = 1; i <= N; i++) {
        int A, B;

        cin>>A>>B;
        ret += B;
        pq.push(A-B);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int min_level = input();
    cout<<upgrade_menu(min_level)<<'\n';

    return 0;
}