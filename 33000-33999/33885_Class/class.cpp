#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX_NUM_OF_CLASS (10+1)

typedef pair<string, int> Time;

typedef struct {
    int c;
    vector<Time> t;
} Class;

int N, M;
Class cl[MAX_NUM_OF_CLASS];

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int s;

        for (cin >> cl[i].c >> s; s > 0; s--) {
            string d;
            int h;

            cin >> d >> h;
            cl[i].t.push_back({d, h});
        }
    }
}

int check_time(const vector<int>& selected) {
    int ret = 0;
    set<Time> allocated;

    for (int i = 0; i < selected.size(); i++) {
        const Class& cur = cl[selected[i]];

        for (int j = 0; j < cur.t.size(); j++) {
            if (allocated.find(cur.t[j]) != allocated.end()) {
                return 0;
            }

            allocated.insert(cur.t[j]);
        }

        ret += cur.c;
    }

    return ret;
}

bool dfs(int c, vector<int>& s) {
    if (c > N) {
        return (check_time(s) >= M);
    }

    s.push_back(c);
    if (dfs(c + 1, s) == true) {return true;}
    s.pop_back();

    return dfs(c + 1, s);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> selected;

    input();
    cout << (dfs(1, selected)?"YES":"NO") << '\n';

    return 0;
}