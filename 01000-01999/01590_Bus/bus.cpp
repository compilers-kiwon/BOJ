#include <iostream>
#include <set>

using namespace std;

void get_depature_time(int start, int interval,
                        int num, set<int>& depature) {
    for (int i = 0; i < num; ++i) {
        depature.insert(start + (i * interval));
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, T;
    set<int> depature_time;

    for (cin >> N >> T; N > 0; --N) {
        int S, I, C;
        cin >> S >> I >> C;
        get_depature_time(S, I, C, depature_time);
    }

    auto it = depature_time.lower_bound(T);

    if (it == depature_time.end()) {
        cout << -1 << '\n';
    } else {
        cout << *it - T << '\n';
    }

    return 0;
}