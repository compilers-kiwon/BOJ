#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    unordered_set<int> used;

    A[0] = 0, used.insert(0);

    for (int i = 1; i <= N; ++i) {
        A[i] = A[i-1] - i;

        if (A[i] < 0 || used.find(A[i]) != used.end()) {
            A[i] = A[i-1] + i;
        }

        used.insert(A[i]);
    }

    cout << A[N] << '\n';
    return 0;
}