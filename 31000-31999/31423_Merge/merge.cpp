#include <iostream>
#include <string>
#include <deque>

using namespace std;

#define MAX_SIZE (500000+1)

int N, h[MAX_SIZE], t[MAX_SIZE], ptr[MAX_SIZE];
string u[MAX_SIZE];
deque<int> merged[MAX_SIZE];


void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> u[i];
        ptr[i] = i;
        merged[i].push_back(i);
    }

    for (int i = 1; i < N; i++) {
        cin >> h[i] >> t[i];
    }
}

void simulate(void) {
    for (int i = 1; i < N; i++) {
        int h_idx = ptr[h[i]];
        int t_idx = ptr[t[i]];

        if (merged[h_idx].size() >= merged[t_idx].size()) {
            for (; !merged[t_idx].empty(); merged[t_idx].pop_front()) {
                merged[h_idx].push_back(merged[t_idx].front());
            }
        } else {
            for (; !merged[h_idx].empty(); merged[h_idx].pop_back()) {
                merged[t_idx].push_front(merged[h_idx].back());
            }

            ptr[h[i]] = t_idx;
        }
    }
}

void print(void) {
    int d_ptr = ptr[h[N-1]];
    deque<int>& m = merged[d_ptr];

    for (; !m.empty(); m.pop_front()) {
        cout << u[m.front()];
    }

    cout << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return 0;
}