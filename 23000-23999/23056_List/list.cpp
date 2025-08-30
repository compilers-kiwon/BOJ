#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_NUM_OF_CLASS (10+1)

typedef pair<int, int> Tag; // <class, name_len>
typedef pair<Tag, string> Student; // <Tag, name>

int N, M, cnt_of_class[MAX_NUM_OF_CLASS];
vector<Student> team[2];

void input(void) {
    cin >> N >> M;

    int c;
    string n;

    for (;cin >> c >> n;) {
        if (c == 0 && n == "0") {
            break;
        }

        if (cnt_of_class[c] < M) {
            cnt_of_class[c]++;
            team[c%2].push_back({{c, n.length()}, n});
        }
    }
}

void print(void) {
    for (int i = 1; i >= 0; i--) {
        for (int j = 0; j < team[i].size(); j++) {
            cout << team[i][j].first.first <<
                    ' ' << team[i][j].second << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    sort(team[0].begin(), team[0].end());
    sort(team[1].begin(), team[1].end());

    print();

    return 0;
}