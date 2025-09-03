#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    cin >> S;
    cout << (S=="(1)"?0:S==")1("?2:1) << '\n';

    return 0;
}