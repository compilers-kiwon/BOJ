#include <iostream>
#include <vector>

using namespace std;

#define NUM_OF_NUMS (6)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int W, L, T;
    vector<int> A, B;

    for (int i = 1; i <= NUM_OF_NUMS; ++i) {
        int n;
        cin >> n;
        A.push_back(n);
    }

    for (int i = 1; i <= NUM_OF_NUMS; ++i) {
        int n;
        cin >> n;
        B.push_back(n);
    }

    W = L = T = 0;

    for (int i = 0; i < NUM_OF_NUMS; ++i) {
        for (int j = 0; j < NUM_OF_NUMS; ++j) {
            if (A[i] > B[j]) {
                ++W;
            } else if (A[i] < B[j]) {
                ++L;
            } else {
                ++T;
            }
        }
    }

    cout << fixed; cout.precision(5);
    cout << (double)W / (double)(W + L) << '\n';

    return 0;
}