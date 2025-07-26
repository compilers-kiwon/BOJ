#include <iostream>

using namespace std;

#define MAX_SIZE (1000+1)

bool visited[MAX_SIZE];

int simulate(int N, int K) {
    int cnt = 0;

    fill(&visited[2], &visited[N+1], false);

    for (int p = 2; p <= N; p++) {
        if (visited[p] == true) {
            continue;
        }

        for (int i = p; i <= N; i += p) {
            if (visited[i] == true) {
                continue;
            }
            
            visited[i] = true;

            if (++cnt == K) {
                return i;
            }
        }
    }

    return 0;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int N, K; cin >> N >> K;) {
        cout << simulate(N, K) << '\n';
    }

    return 0;
}