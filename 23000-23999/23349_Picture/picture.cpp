#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define MAX_TIME (50000+1)

map<string, vector<int>> time_table;

void input(void) {
    int N;
    set<string> submitted;

    for (cin >> N; N > 0; N--) {
        string n, p;
        int s, e;

        cin >> n >> p >> s >> e;

        if (submitted.find(n) != submitted.end()) {
            continue;
        }

        submitted.insert(n);

        if (time_table.find(p) == time_table.end()) {
            time_table[p] = vector<int>(MAX_TIME, 0);
        }

        for (int t = s; t < e; t++) {
            time_table[p][t]++;
        }
    }
}

void find_busy_time(string& p, int& s, int& e) {
    int max_busy_num = 0;

    for (auto it = time_table.begin(); it != time_table.end(); it++) {
        int prev_num = 0;
        int start_time;

        for (int t = 1; t < MAX_TIME; t++) {
            int cur_num = it->second[t];

            if (prev_num != cur_num) {
                if (prev_num != 0) {
                    if (prev_num > max_busy_num) {
                        p = it->first, s = start_time, e = t;
                        max_busy_num = prev_num;
                    }
                }

                start_time = t;
            }

            prev_num = cur_num;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string busy_place;
    int busy_start_time, busy_end_time;

    input();
    find_busy_time(busy_place, busy_start_time, busy_end_time);
    cout << busy_place << ' ' << busy_start_time << ' ' << busy_end_time << '\n';

    return 0;
}