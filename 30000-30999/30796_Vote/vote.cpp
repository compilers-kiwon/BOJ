#include <iostream>

using namespace std;

#define MAX_SIZE (250000+1)

bool participated[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int v, k, cnt;
    cin >> v >> k, cnt = 0;
    fill(&participated[1], &participated[v+1], true);

    for (int i = v; i > 0; --i) {
        if (participated[i] == false) {
            continue;
        }

        ++cnt, participated[max(0, i - k)] = false;
    }

    cout << cnt << '\n';

    for (int i = v; i > 0; --i) {
        if (participated[i] == true) {
            cout << i << '\n';
        }
    }

    return 0;
}