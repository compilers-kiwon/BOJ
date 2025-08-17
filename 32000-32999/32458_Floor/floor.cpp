#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string x;
    cin >> x;
    cout << x.substr(0, x.find('.')) << '\n';

    return 0;
}