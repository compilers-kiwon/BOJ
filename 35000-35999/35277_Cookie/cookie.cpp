#include <iostream>

using namespace std;

const int required = 900 + 60 + 600 + 170 + 160 + 110;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    cout << N / required << '\n';

    return 0;
}