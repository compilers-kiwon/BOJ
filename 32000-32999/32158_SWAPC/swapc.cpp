#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S;
    queue<int> pos[0x100];

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        pos[S[i]].push(i);
    }

    for (; !pos['C'].empty() && !pos['P'].empty();) {
        int c_pos = pos['C'].front();
        int p_pos = pos['P'].front();

        swap(S[c_pos], S[p_pos]);
        pos['C'].pop(), pos['P'].pop();
    }

    cout << S << '\n';

    return 0;
}