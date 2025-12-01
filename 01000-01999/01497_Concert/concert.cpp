#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE (10+1)

int N, M;
string playable[MAX_SIZE];

int play_music(const vector<int>& g) {
    string list = string(M, 'N');

    for (int i = 0; i < g.size(); i++) {
        string s = playable[g[i]];

        for (int j = 0; j < M; j++) {
            list[j] = (list[j]=='N'&&s[j]=='N')?'N':'Y';
        }
    }

    int ret = 0;

    for (int i = 0; i < M; i++) {
        ret += (list[i]=='Y')?1:0;
    }

    return ret;
}

void dfs(int cur_guitar, vector<int>& selected, int& max_cnt, int& min_cnt) {
    if (cur_guitar > N) {
        int p = play_music(selected);

        if (p >= max_cnt) {
            if (p > max_cnt) {
                max_cnt = p;
                min_cnt = selected.size();
            } else {
                min_cnt = min(min_cnt, (int)selected.size());
            }
        }

        return;
    }

    selected.push_back(cur_guitar);
    dfs(cur_guitar + 1, selected, max_cnt, min_cnt);
    selected.pop_back();

    dfs(cur_guitar + 1, selected, max_cnt, min_cnt);
}

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string g;
        cin >> g >> playable[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    vector<int> selected;

    int min_cnt = MAX_SIZE;
    int max_num_of_played = 0;
    

    dfs(1, selected, max_num_of_played, min_cnt);
    cout << ((max_num_of_played==0)?-1:min_cnt) << '\n';

    return 0;
}