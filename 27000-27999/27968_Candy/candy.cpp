#include <iostream>
#include <map>

using namespace std;

typedef long long int int64;

void build_candy_table(map<int64, int>& t, int M) {
    int64 cur = 0LL;

    for (int i = 1; i <= M; ++i) {
        int64 A;
        cin >> A;
        t[(cur+=A)] = i;
    }
}

void simulate(map<int64, int>& t, int N) {
    for (int i = 1; i <= N; ++i) {
        int64 B;
        
        cin >> B;

        auto it = t.lower_bound(B);

        if (it == t.end()) {
            cout << "Go away!\n";
        } else {
            cout << it->second << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    map<int64, int> table;

    cin >> N >> M;
    build_candy_table(table, M);
    simulate(table, N);

    return 0;
}