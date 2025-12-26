#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    cout << N / M + ((N%M==0)?0:1) << '\n';

    return 0;
}