#include <iostream>

using namespace std;

#define MAX_SIZE (15)

bool simulate(int A[], int carrot) {
    for (int i = 1; i <= MAX_SIZE; i++) {
        if (carrot < A[i]) {
            return false;
        }
        
        if (carrot == A[i]) {
            carrot = 0;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A[MAX_SIZE+1], max_len;

    max_len = 0;

    for (int i = 1; i <= MAX_SIZE; i++) {
        cin >> A[i];
        max_len = max(max_len, A[i]);
    }

    cout << (simulate(A, max_len)?max_len:max_len+1) << '\n';

    return 0;
} 