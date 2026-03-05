#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define INF (-1000000)

void input(unordered_map<int, vector<int>>& players) {
    int N;

    cin >> N;

    for (int rank = 1; rank <= N; ++rank) {
        int A;
        cin >> A;
        players[A].push_back(rank);
    }

    for (int rank = 1; rank <= N; ++rank) {
        int B;
        cin >> B;
        players[B].push_back(rank);
    }
}

void simulate(vector<pair<int, int>>& increased,
                unordered_map<int, vector<int>>& records) {
    int max_diff = INF;
    
    for (auto it = records.begin(); it != records.end(); ++it) {
        int back_number = it->first;
        int prev_rank = it->second.front();
        int last_rank = it->second.back();
        int cur_diff = prev_rank - last_rank;

        if (cur_diff >= max_diff) {
            if (cur_diff > max_diff) {
                increased.clear(), max_diff = cur_diff;
            }

            increased.push_back({last_rank, back_number});
        }
    }
}

void print(const vector<pair<int, int>>& increased) {
    for (int i = 0; i < increased.size(); ++i) {
        cout << increased[i].second << ' ';
    }

    cout << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<pair<int, int>> inc;
    unordered_map<int, vector<int>> records;

    input(records);
    simulate(inc, records);

    sort(inc.begin(), inc.end());
    print(inc);

    return 0;
}