#include <iostream>
#include <string>

using namespace std;

const string STR = "UOS";

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    size_t x;
    cin >> x;
    cout << STR[(x - 1)%STR.length()] << '\n';

    return 0;
}