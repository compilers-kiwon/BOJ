#include <iostream>

using namespace std;

bool is_qualified(void) {
    int s, c, a, r;

    cin >> s >> c >> a >> r;

    if (s >= 1000 || c >= 1600 || a >= 1500 || (r != -1 && r <= 30)) {
        return true;
    }

    return false;
}

int simulate(int num_of_candidates) {
    int ret = 0;

    for (int i = 1; i <= num_of_candidates; ++i) {
        ret += is_qualified()?1:0;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    cout << simulate(N) << '\n';

    return 0;
}