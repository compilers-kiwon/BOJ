#include <iostream>
#include <queue>

using namespace std;

#define MAX_NUM_OF_GUESTS (100000+1)
#define MAX_NUM_OF_SUSHI (200000+1)

int N, M, cnt[MAX_NUM_OF_GUESTS];
queue<int> order[MAX_NUM_OF_SUSHI];

void input(queue<int>& s) {
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        int k;

        for (cin >> k; k > 0; --k) {
            int A;
            cin >> A;
            order[A].push(i);
        }
    }

    for (; M > 0; --M) {
        int B;
        cin >> B;
        s.push(B);
    }
}

void simulate(queue<int>& s) {
    for (; !s.empty(); s.pop()) {
        int cur_sushi = s.front();

        if (order[cur_sushi].empty()) {
            continue;
        }

        int guest = order[cur_sushi].front();
        ++cnt[guest], order[cur_sushi].pop();
    }
}

void print(void) {
    for (int i = 1; i <= N; ++i) {
        cout << cnt[i] << ((i==N)?'\n':' ');
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int> sushi;

    input(sushi);
    simulate(sushi);
    print();

    return 0;
}