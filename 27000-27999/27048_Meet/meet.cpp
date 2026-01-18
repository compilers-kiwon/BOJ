#include <iostream>
#include <deque>

using namespace std;

#define MAX_SIZE (1000+1)

int N, P, C, num_of_cows[MAX_SIZE];

void input(void) {
    cin >> N >> P >> C;

    for (int i = 1; i <= N; i++) {
        int X;
        cin >> X;
        num_of_cows[X]++;
    }
}

int simulate(void) {
    int ret, sum_of_cows;
    deque<int> dq;

    ret = sum_of_cows = 0;

    for (int i = 1; i < P; i++) {
        int adj_num_of_cows = num_of_cows[i];

        for (sum_of_cows += adj_num_of_cows, dq.push_back(i);
                !dq.empty() && sum_of_cows > C; dq.pop_front()) {
            sum_of_cows -= num_of_cows[dq.front()];
        }

        ret = max(ret, (int)dq.size());
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}