#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    cout << (N*100>=M?"Yes":"No") << '\n';

    return 0;
}