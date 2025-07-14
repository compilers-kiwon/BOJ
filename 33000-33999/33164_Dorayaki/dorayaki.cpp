#include <iostream>
#include <vector>

using namespace std;

void get_num(int size, vector<int>& arr) {
    for (int i = 0; i < size; i++) {
        int n;
        cin >> n;
        arr.push_back(n);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    vector<int> A, B;

    cin >> N >> M;

    get_num(N, A);
    get_num(M, B);
    
    int sum = 0;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            sum += (A[n] + B[m]) * max(A[n], B[m]);
        }
    }

    cout << sum <<'\n';

    return 0;
}