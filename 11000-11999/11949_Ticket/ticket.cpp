#include <iostream>

using namespace std;

#define MAX_SIZE (100)

void input(int& N, int& M, int A[]) {
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
}

void simulate(int N, int M, int A[]) {
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j < N; ++j) {
            if ((A[j] % i) > (A[j+1] % i)) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

void print(int N, int A[]) {
    for (int i = 1; i <= N; ++i) {
        cout << A[i] << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, A[MAX_SIZE+1];

    input(N, M, A);
    simulate(N, M, A);
    print(N, A);

    return 0;
}