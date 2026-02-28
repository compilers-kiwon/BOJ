#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)

int G, P, available_gate[MAX_SIZE];

int find_available_gate(int g) {
    int& ret = available_gate[g];

    if (ret != g) {
        ret = find_available_gate(ret);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt;

    cin >> G >> P, cnt = 0;

    for (int i = 1; i <= G; ++i) {
        available_gate[i] = i;
    }

    for (int i = 1; i <= P; ++i) {
        int g, a;

        cin >> g;
        a = find_available_gate(g);

        if (a == 0) {
            break;
        }

        available_gate[a] = a - 1, ++cnt;
    }

    cout << cnt << '\n';

    return 0;
}