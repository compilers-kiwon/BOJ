#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, L;
    string num;

    cin >> N >> L;

    for (int i = 1; i < L; i++) {
        num.push_back('1');
    }

    num += to_string(N);
    cout << num << '\n';

    return 0;
}