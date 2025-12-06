#include <iostream>
#include <string>

using namespace std;

const int TAIL_LEN = 5;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S;

    cin >> N >> S;
    cout << S.substr(N - TAIL_LEN) << '\n';

    return 0;
}