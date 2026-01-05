#include <iostream>
#include <vector>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (100)

typedef pair<int, int> State;

int N, T, D[MAX_SIZE+1]; 
int S[MAX_SIZE+1][MAX_SIZE+1];
State dp[MAX_SIZE+1][MAX_SIZE+1];

void input(void) {
    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        for (int t = 0; t <= T; t++) {
            cin >> S[i][t];
        }
    }

    for (int t = 0; t <= T; t++) {
        cin >> D[t];
    }

    for (int t = 0; t <= T; t++) {
        dp[1][t] = {S[1][t], t};
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = {dp[i-1][0].first + S[i][0], 0};
        
        for (int t = 1; t <= T; t++) {
            dp[i][t] = {TBD, TBD};
        }
    }
}

void backtrace(int subject, int acc_time, vector<int>& t) {
    if (subject == 0) {
        return;
    }

    int cur_study_time = dp[subject][acc_time].second;
    int prev_study_time = acc_time - cur_study_time;

    t.push_back(cur_study_time);
    backtrace(subject - 1, prev_study_time, t);
}

State get_dp(int subject, int acc_time) {
    State& ret = dp[subject][acc_time];

    if (ret.first != TBD) {
        return ret;
    }

    ret = {0, 0};

    for (int t = 0; t <= acc_time; t++) {
        int cur_study_time = acc_time - t;
        int cur_subject_score = S[subject][cur_study_time];
        State s = get_dp(subject - 1, t);

        if (s.first + cur_subject_score > ret.first) {
            ret.first = s.first + cur_subject_score;
            ret.second = cur_study_time;
        }
    }

    return ret;
}

int get_time_for_max_score(void) {
    int ret;
    int max_score = -1000000000;

    for (int t = 0; t <= T; t++) {
        State s = get_dp(N, t);

        if (s.first - D[t] > max_score) {
            max_score = s.first - D[t];
            ret = t;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int total_time;
    vector<int> study_time;

    input();
    total_time = get_time_for_max_score();
    backtrace(N, total_time, study_time);

    cout << dp[N][total_time].first - D[total_time] << '\n';

    for (int i = N - 1; i >= 0; i--) {
        cout << study_time[i] << ((i==0)?'\n':' ');
    }

    return 0;
}