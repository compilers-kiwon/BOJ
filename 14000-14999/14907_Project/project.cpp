#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (26)
#define get_idx(c) ((int)((c)-'A'))

typedef struct{
    int time;
    string prev;
} Task;

int dp[MAX_SIZE];
Task t[MAX_SIZE];
string all_tasks;

void get_task(const vector<string>& p) {
    int idx = get_idx(p[0].front());
    t[idx].time = stoi(p[1]);
    t[idx].prev = (p.size()==2)?"":p[2];
    all_tasks.push_back(p[0].front());
}

void parse(const string& str) {
    string cur;
    vector<string> params;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            params.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }

    get_task(params);
}

void input(void) {
    for (;;) {
        string buf;
        getline(cin, buf);

        if (buf.empty()) {
            break;
        }

        buf.push_back(' ');
        parse(buf);
    }
}

int get_dp(int idx) {
    int& ret = dp[idx];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    const string& p = t[idx].prev;

    for (int i = 0; i < p.length(); ++i) {
        ret = max(ret, get_dp(get_idx(p[i])));
    }

    return (ret += t[idx].time);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_time = 0;

    input();
    fill(dp, dp + MAX_SIZE, TBD);

    for (int i = 0; i < all_tasks.length(); ++i) {
        max_time = max(max_time, get_dp(get_idx(all_tasks[i])));
    }

    cout << max_time << '\n';

    return 0;
}