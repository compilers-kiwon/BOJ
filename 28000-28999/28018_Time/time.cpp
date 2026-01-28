#include <iostream>
#include <queue>

using namespace std;

#define MAX_TIME (1000000+1)

int num_of_occupied[MAX_TIME+1];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, Q;

    for (cin >> N; N > 0; --N) {
        int S, E;
        cin >> S >> E;
        ++num_of_occupied[S], --num_of_occupied[E+1];
    }

    for (int t = 1; t < MAX_TIME; t++) {
        num_of_occupied[t] += num_of_occupied[t-1];
    }

    for (cin >> Q; Q > 0; --Q) {
        int q;
        cin >> q;
        cout << num_of_occupied[q] << '\n';
    }

    return 0;
}