#include <iostream>
#include <deque>

using namespace std;

#define MAX_NUM (100000+1)
#define MAX_SIZE (200000+1)

int N, K, a[MAX_SIZE];
deque<int> included[MAX_NUM];

void input(void) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
}

int simulate(void) {
    int ret = 0;

    included[a[1]].push_back(1);

    for (int h = 1, t = 2; t <= N;t++) {        
        included[a[t]].push_back(t);

        if (included[a[t]].size() > K) {
            int new_head_pos = included[a[t]].front() + 1;

            for (; h < new_head_pos; h++) {
                int excluded_num = a[h];
                included[excluded_num].pop_front();
            }
        }

        ret = max(ret, t - h + 1);
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