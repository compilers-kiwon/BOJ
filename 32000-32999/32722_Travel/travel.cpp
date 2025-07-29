#include <iostream>

using namespace std;

#define MAX_SIZE (3)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    bool result = true;
    pair<int, int> path[] = {
        {1, 3}, {6, 8}, {2, 5}
    };

    for (int i = 0; i < MAX_SIZE; i++) {
        int n;
        cin >> n;

        if (n != path[i].first && n != path[i].second) {
            result = false;
            break;
        }
    }

    cout << (result?"JAH":"EI") << '\n';

    return 0;
}