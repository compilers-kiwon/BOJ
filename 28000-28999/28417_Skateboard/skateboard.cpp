#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FIRST_RUN_POS (0)
#define NUM_OF_RUNS (2)

#define FIRST_TRICK_POS (2)
#define NUM_OF_TRICKS (5)

int get_max_scores(const vector<int>& scores,
                    int start, int num, int num_of_targets) {
    int ret = 0;
    priority_queue<int> pq;

    for (int i = 0; i < num; ++i) {
        pq.push(scores[start+i]);
    }

    for (int i = 0; i < num_of_targets; ++i) {
        ret += pq.top();
        pq.pop();
    }

    return ret;
}

int get_max_score_of_runs(const vector<int>& scores) {
    return get_max_scores(scores, FIRST_RUN_POS, NUM_OF_RUNS, 1);
}

int get_max_score_of_tricks(const vector<int>& scores) {
    return get_max_scores(scores, FIRST_TRICK_POS, NUM_OF_TRICKS, 2);
}

int get_cur_score(const vector<int>& cur) {
    return (get_max_score_of_runs(cur) +
                get_max_score_of_tricks(cur));
}

void input(vector<int>& score) {
    for (int i = 0; i < NUM_OF_RUNS + NUM_OF_TRICKS; ++i) {
        int s;
        cin >> s;
        score.push_back(s);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, winner_score;

    for (cin >> N, winner_score = 0; N > 0; --N) {
        vector<int> s;
        input(s);
        winner_score = max(winner_score, get_cur_score(s));
    }

    cout << winner_score << '\n';

    return 0;
}