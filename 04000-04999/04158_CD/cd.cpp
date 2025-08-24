#include <iostream>

using namespace std;

#define MAX_SIZE (1000000)

int cd1[MAX_SIZE], cd2[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int N, M; cin >> N >> M;) {
        if (N == 0 && M == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            cin >> cd1[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> cd2[i];
        }

        int cnt, p1, p2;
        
        for (cnt = p1 = p2 = 0; p1 < N && p2 < M;) {
            if (cd1[p1] == cd2[p2]) {
                ++p1, ++p2, ++cnt;
            } else {
                if (cd1[p1] < cd2[p2]) {
                    ++p1;
                } else {
                    ++p2;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}