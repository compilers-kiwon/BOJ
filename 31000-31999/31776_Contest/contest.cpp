#include <iostream>

using namespace std;

#define UNSOLVED (-1)
#define NUM_OF_PROBLEMS (3)

bool simulate(int T[]) {
    int solved = 0;

    for (int i = 1; i <= NUM_OF_PROBLEMS; i++) {
        solved += (T[i]!=UNSOLVED)?1:0;
    }

    if (solved == 0) {
        return false;
    }

    for (int i = 1; i <= NUM_OF_PROBLEMS; i++) {
        if (T[i] == UNSOLVED) {
            continue;
        }

        for (int j = 1; j < i; j++) {
            if (T[j] == UNSOLVED || T[j] > T[i]) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt;

    for (cin >> N, cnt = 0; N > 0; N--) {
        int T[NUM_OF_PROBLEMS+1];
        
        for (int i = 1; i <= NUM_OF_PROBLEMS; i++) {
            cin >> T[i];
        }

        cnt += simulate(T)?1:0;
    }

    cout << cnt << '\n';

    return 0;
}