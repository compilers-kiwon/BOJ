#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const string kinds[] = {"EMPTY", "O", "S", "OS"};

int is_odd(int n) {
    return ((n % 2) == 1);
}

int is_square(int n) {
    int r = sqrt(n);
    return ((r * r) == n);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, k;
        cin >> N;
        
        k = (is_odd(N) << 0) + (is_square(N) << 1);
        cout << kinds[k] << '\n';
    }

    return 0;
}