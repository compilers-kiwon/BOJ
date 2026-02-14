#include <iostream>
#include <cmath>

using namespace std;

#define MAX_SIZE (500000+1)

int M, p[MAX_SIZE];

void input(void) {
    cin >> M;

    for (int i = 1; i <= M; ++i) {
        cin >> p[i];
    }
}

int simulate(void) {
    int max_inc, max_dec;

    max_inc = max_dec = 0;

    for (int i = 2, inc = 0, dec = 0; i <= M; ++i) {
        if (p[i-1] < p[i]) {
            ++inc, dec = 0;
        } else if (p[i-1] > p[i]) {
            ++dec, inc = 0;
        }

        max_inc = max(max_inc, inc), max_dec = max(max_dec, dec);
    }

    return max(max_dec, max_inc);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() + 1 << '\n';

    return 0;
}