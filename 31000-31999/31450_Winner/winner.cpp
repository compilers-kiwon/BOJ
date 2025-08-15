#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M, K;
    cin >> M >> K;
    cout << (((M >= K) && ((M % K) == 0))?"Yes":"No") << '\n';

    return 0;
}