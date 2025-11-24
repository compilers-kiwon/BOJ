#include <iostream>
#include <vector>

using namespace std;

enum {
    LEVEL = 0,
    LANG = 1,
    READING = 2,
    LISTENING = 3,
    MAX_SIZE = 4,
};

const int min_listening_score = 50;
const int passing_score[] = {0, 100, 90};
const int cutoff_score[] = {0, 19, 19};

bool simulate(const vector<int>& score) {
    if (!(score[LEVEL] == 1 || score[LEVEL] == 2)) {
        return false;
    }

    if (!(score[LISTENING] >= min_listening_score)) {
        return false;
    }

    if ((score[LANG] * 3) < passing_score[score[LEVEL]]
        && (score[READING] * 3) < passing_score[score[LEVEL]]) {
        return true;
    }

    if ((score[READING] - cutoff_score[READING]) < 3
            || (score[LANG] - cutoff_score[LANG]) < 3) {
        return true;
    }

    return false;
}

void input(vector<vector<int>>& table) {
    int Q;

    for (cin >> Q; Q > 0; Q--) {
        vector<int> s;

        for (int i = 0; i < MAX_SIZE; i++) {
            int n;
            cin >> n;
            s.push_back(n); 
        }

        table.push_back(s);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<vector<int>> score_table;

    input(score_table);

    for (int i = 0; i < score_table.size(); i++) {
        cout << (simulate(score_table[i])?"YES":"NO") << '\n';
    }

    return 0;
}