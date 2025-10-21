#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define TARGET_CREDIT (22)
#define MAX_NUM_OF_GROUPS (15+1)

typedef struct {
    int C, D, S, E;
} Subject;

int N, cnt;
vector<Subject> subject_group[MAX_NUM_OF_GROUPS];

int get_minutes(const string& s) {
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    return ((hh * 60) + mm);
}

bool is_conflicted(const Subject& candidate, 
                    const vector<Subject>& selected) {
    for (int i = 0; i < selected.size(); i++) {
        const Subject& cur = selected[i];

        if (cur.D != candidate.D) {
            continue;
        }

        if (!(cur.E < candidate.S || candidate.E < cur.S)) {
            return true;
        }
    }

    return false;
}

void dfs(int cur_group, vector<Subject>& selected, int cur_credit) {
    if (cur_group > N) {
        cnt += (cur_credit==TARGET_CREDIT)?1:0;
        return;
    }

    for (int i = 0; i < subject_group[cur_group].size(); i++) {
        const Subject& s = subject_group[cur_group][i];

        if (is_conflicted(s, selected) != true
                && (cur_credit + s.C) <= TARGET_CREDIT) {
            selected.push_back(s);
            dfs(cur_group + 1, selected, cur_credit + s.C);
            selected.pop_back();
        }
    }

    dfs(cur_group + 1, selected, cur_credit);
}

void read_group(vector<Subject>& g) {
    int num_of_subjects;

    for (cin >> num_of_subjects; num_of_subjects > 0; num_of_subjects--) {
        Subject s;
        string start_time, end_time;

        cin >> s.C >> s.D >> start_time >> end_time;
        s.S = get_minutes(start_time), s.E = get_minutes(end_time) - 1;
        g.push_back(s);
    }
}

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        read_group(subject_group[i]);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Subject> selected;

    input();
    dfs(1, selected, 0);
    cout << cnt << '\n';

    return 0;
}