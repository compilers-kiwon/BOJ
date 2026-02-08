#include <iostream>

using namespace std;

#define MY_STR ("I love DGU")

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; --N) {
        cout << MY_STR << '\n';
    }

    return 0;
}