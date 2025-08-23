#include <iostream>

using namespace std;

#define MAX_BREED_ID (3)
#define MAX_SIZE (100000+1)

int N, Q, cnt[MAX_SIZE][MAX_BREED_ID+1];
int a[MAX_SIZE], b[MAX_SIZE];

void input(void) {
    cin >> N >> Q;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= MAX_BREED_ID; col++) {
            cnt[row][col] = cnt[row-1][col];
        }

        int id;
        cin >> id;
        cnt[row][id]++;
    }

    for (int i = 1; i <= Q; i++) {
        cin >> a[i] >> b[i];
    }
}

void simulate(void) {
    for (int i = 1; i <= Q; i++) {
        for (int id = 1; id <= MAX_BREED_ID; id++) {
            cout << cnt[b[i]][id] - cnt[a[i]-1][id] << ' ';
        }

        cout << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    return 0;
}