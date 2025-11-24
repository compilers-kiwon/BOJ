#include <iostream>
#include <string>

using namespace std;

const int cost = 1550;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string A, B;
    cin >> A >> B;
    cout << ((A!=B)?cost:0) << '\n';

    return 0;
}