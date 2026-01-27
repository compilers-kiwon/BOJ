#include <iostream>
#include <set>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    set<int> s, not_connected;
    set<pair<int, int>> river;

    cin >> N >> M;

    int64 cost = (((int64)N * (int64)(N + 1)) / 2LL)
                    - 1LL + (int64)(N - 1);

    for (int i = 1; i <= M; ++i) {
        int a, b;

        cin >> a >> b;
        river.insert({a, b});

        if (a == 1) {
            cost -= (int64)(b + 1);
            s.insert(b), not_connected.insert(b);
        }
    }    

    for (auto it = s.begin(); it != s.end(); ++it) {
        int city = *it;

        for (int adj = 2; adj <= N; ++adj) {
            if (city != adj && not_connected.find(adj) == not_connected.end()
                    && river.find({min(adj, city), max(adj, city)}) == river.end()) {
                cost += (int64)(adj + city);
                not_connected.erase(city);
                break;
            } 
        }
    }

    cout << cost << '\n';

    return 0;
}