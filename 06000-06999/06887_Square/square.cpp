#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    cout << "The largest square has side length " << (int)sqrt(n) << ".\n";

    return 0;
}