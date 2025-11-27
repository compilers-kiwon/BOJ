#include <iostream>
#include <unordered_set>

using namespace std;

int N, M;
unordered_set<int> study;

bool input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int x, y, s;

        for (cin >> x, s = 0; x > 0; x--) {
            cin >> y;
            s += 1 << (y - 1);
        }

        if (study.find(s) != study.end()) {
            return false;
        }

        study.insert(s);
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    if (input() == false) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < M; i++) {
            cout << (1 << i) << ((i==M-1)?'\n':' ');
        }
    }

    return 0;
}