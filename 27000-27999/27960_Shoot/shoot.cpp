#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Sa, Sb;
    cin >> Sa >> Sb;
    cout << (Sa ^ Sb) << '\n';

    return 0;
}