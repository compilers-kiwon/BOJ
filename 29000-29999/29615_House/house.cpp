#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> candidate(N+1);
    vector<bool> is_friend(N+1, false);

    for (int i = 1; i <= N; ++i) {
        cin >> candidate[i];
    }

    for (int i = 1; i <= M; ++i) {
        int n;
        cin >> n;
        is_friend[n] = true;
    }

    int cnt = 0;

    for (int i = 1; i <= M; ++i) {
        if (is_friend[candidate[i]] == false) {
            ++cnt;
        }
    }

    cout << cnt << '\n';

    return 0;
}