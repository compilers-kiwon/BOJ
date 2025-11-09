#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define NUM_OF_DAYS (7)
#define NUM_OF_HOURS (24)

const string day[NUM_OF_DAYS] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

unordered_map<string, int> num_table;
unordered_set<int> time_table[NUM_OF_DAYS][NUM_OF_HOURS];

inline int get_day_idx(const string& s) {
    int ret;

    for (ret = 0; ret < NUM_OF_DAYS; ret++) {
        if (day[ret] == s) {
            break;
        }
    }

    return ret;
}

int count_union(const unordered_set<int>& s1, const unordered_set<int>& s2) {
    int ret = s1.size();

    for (auto it = s2.begin(); it != s2.end(); it++) {
        if (s1.find(*it) == s1.end()) {
            ret++;
        }
    }

    return ret;
}

void find_max_attendace_days(void) {
    int day_1, hour_1, day_2, hour_2, max_cnt;

    max_cnt = 0;

    for (int d1 = 0; d1 < NUM_OF_DAYS; d1++) {
        for (int h1 = 0; h1 < NUM_OF_HOURS; h1++) {
            for (int d2 = d1; d2 < NUM_OF_DAYS; d2++) {
                for (int h2 = (d1==d2)?h1+1:0; h2 < NUM_OF_HOURS; h2++) {
                    int cur_cnt = count_union(time_table[d1][h1], time_table[d2][h2]);

                    if (cur_cnt > max_cnt) {
                        max_cnt = cur_cnt;
                        day_1 = d1, hour_1 = h1;
                        day_2 = d2, hour_2 = h2;
                    }
                }
            }
        }
    }

    cout << day[day_1] << ' ' << hour_1 << '\n';
    cout << day[day_2] << ' ' << hour_2 << '\n';
}

void input(void) {
    int N, num;

    for (cin >> N, num = 1; N > 0; N--) {
        string n, d;
        int p, ptr, idx;

        cin >> n >> d >> p;
        idx = get_day_idx(d);

        if (num_table.find(n) == num_table.end()) {
            ptr = (num_table[n] = num++);
        } else {
            ptr = num_table[n];
        }

        for (int i = 1; i <= p; i++) {
            int start, end;
            char c;

            cin >> start >> c >> end;

            for (; start < end; start++) {
                time_table[idx][start].insert(ptr);
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    find_max_attendace_days();

    return 0;
}