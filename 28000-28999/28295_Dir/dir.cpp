#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_DIRS (10)

const string d = "NESW";

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int i, cur;

    for (i = 1, cur = 0; i <= NUM_OF_DIRS; ++i) {
        int t;
        cin >> t;
        cur += t;
    }

    cout << d[cur%d.length()] << '\n';

    return 0;
}