#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int int64;

int input(vector<int64>& arr) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int64 A;
        cin >> A;
        arr.push_back(A);
    }

    return N;
}

bool simulate(vector<int64>& A) {
    int64 a, b;

    a = b = 0LL, sort(A.begin(), A.end());

    for (int h = 0, t = A.size() - 1; h < t; ++h, --t) {
        a += A[t], b += A[h];

        if (a <= b) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int64> A;

    N = input(A);

    if (N % 2 == 1) {
        cout << "Bob\n";
    } else {
        cout << (simulate(A)?"Alice":"Bob") << '\n';
    }

    return 0;
}