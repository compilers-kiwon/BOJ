#include <iostream>

using namespace std;

#define MAX_SIZE (1000000+1)

bool prize[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, p, m;

    cin >> n >> p >> m;
    prize[p] = true;

    for (int i = 1; i <= m; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        swap(prize[c1], prize[c2]);
    }

    for (int i = 1; i <= n; i++) {
        if (prize[i] == true) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}