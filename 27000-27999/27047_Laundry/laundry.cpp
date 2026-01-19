#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (1000+1)

int N, top[MAX_SIZE], pos[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int w;
        cin >> top[i] >> w;
        pos[w] = i;
    }
}

int simulate(void) {
    int ret = 0;
    vector<int> w;

    for (int i = 1; i <= N; i++) {
        w.push_back(pos[top[i]]);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ret += (w[i]>w[j])?1:0;
        }
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