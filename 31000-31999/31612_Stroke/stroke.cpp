#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    int N, sum, num_of_strokes[0x100];

    cin >> N >> S, sum = 0;
    num_of_strokes['j'] = 2, num_of_strokes['o'] = 1, num_of_strokes['i'] = 2;

    for (int i = 0; i < N; i++) {
        sum += num_of_strokes[S[i]];
    }

    cout << sum << '\n';

    return 0;
}