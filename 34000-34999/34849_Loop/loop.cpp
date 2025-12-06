#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    const int UPPER = 10000;
    int N;

    cin >> N;
    cout << ((N<=UPPER)?"Accepted":"Time limit exceeded") << '\n';

    return 0;
}