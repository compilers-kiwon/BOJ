#include <iostream>
#include <vector>

using namespace std;

int simulate(int M, int N, vector<int>& result) {
    for (int i = 1; i <= N; i++) {
        int d = M / N;
        int r = M % N;
        result.push_back(d + r), M -= d + r;
    }

    return M;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M, N, r;
    vector<int> c;

    cin >> M >> N;
    r = simulate(M, N, c);

    for (int i = 0; i < N; i++) {
        cout << c[i] << ((i==N-1)?'\n':' ');
    }

    cout << r << '\n';

    return 0;
}