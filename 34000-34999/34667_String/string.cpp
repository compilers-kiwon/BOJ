#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S, T;
    cin >> S >> T;
    cout << S.front() << S << '\n';

    return 0;
}