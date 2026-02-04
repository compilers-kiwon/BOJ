#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

int input(map<string, multiset<int>>& player) {
    int P, N, M;
    vector<int> S;

    cin >> P;

    for (int i = 0; i < P; ++i) {
        int score;
        cin >> score;
        S.push_back(score);
    }

    for (cin >> N; N > 0; --N) {
        int W;

        cin >> W;

        for (int i = 0; i < P; ++i) {
            string name;
            cin >> name;
            player[name].insert(W * S[i]);
        }
    }

    cin >> M;

    return M;
}

void build_rank_table(map<string, multiset<int>>& player,
                        map<int, set<string>>& rt, int counted) {
    for (auto it = player.begin(); it != player.end(); ++it) {
        int total = 0;
        auto sit = it->second.rbegin();

        for (int i = 0; i < counted && sit != it->second.rend(); ++i, ++sit) {
            total += *sit;
        }

        rt[total].insert(it->first);
    }
}

void print_rank(map<int, set<string>>& rt) {
    int cur = 1;

    for (auto it1 = rt.rbegin(); it1 != rt.rend(); ++it1) {
        const set<string>& athletes = it1->second;

        for (auto it2 = athletes.begin(); it2 != athletes.end(); ++it2) {
            cout << cur << ": " << *it2 << '\n';
        }

        cur += athletes.size();
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int counted;
        map<string, multiset<int>> player;
        map<int, set<string>> rt;

        counted = input(player);
        build_rank_table(player, rt, counted);

        cout << "Case #" << t << ":\n";
        print_rank(rt);
    }

    return 0;
}