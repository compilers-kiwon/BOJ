#include <iostream>
#include <string>

using namespace std;

int table[0x100][0x100];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    table['R']['S'] = table['S']['P'] = table['P']['R'] = 1;

    int N, S_score, T_score;
    string S, T;

    cin >> N >> S >> T;
    S_score = T_score = 0;

    for (int i = 0; i < N; i++) {
        S_score += table[S[i]][T[i]];
        T_score += table[T[i]][S[i]];
    }

    cout << S_score << ' ' << T_score << '\n';

    return 0;
}