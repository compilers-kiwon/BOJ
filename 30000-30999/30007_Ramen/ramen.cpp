#include <iostream>

using namespace std;

int ramen_fomular(int A, int B, int X) {
    return (A * (X - 1) + B);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        int A, B, X;
        cin >> A >> B >> X;
        cout << ramen_fomular(A, B, X) << '\n';
    }

    return 0;
}