#include <iostream>

using namespace std;

#define INF (0x7FFFFFFF)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, winner;

    cin>>N;
    winner = INF;

    for (int n = 1; n <= N; n++) {
        int A, B, C;

        cin>>A>>B>>C;

        if ((A + B + C) >= 512 && (A + B + C) < winner) {
            winner = (A + B + C);
        }
    }

    cout<<(winner==INF?-1:winner)<<'\n';

    return 0;
}