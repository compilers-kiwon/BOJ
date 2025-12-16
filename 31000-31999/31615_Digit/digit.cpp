#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    cout << to_string(A + B).length() << '\n';

    return 0;
}