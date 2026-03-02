#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

double input(int& left_removed, int& right_removed,
            deque<double>& score) {
    int N;
    double sum = 0.0;

    for (cin >> N >> left_removed >> right_removed; N > 0; --N) {
        int s;
        cin >> s;
        sum += s, score.push_back(s);
    }

    sort(score.begin(), score.end());
    return sum;
}

double simulate(int left_removed, int right_removed,
                    double total, deque<double>& score) {
    for (int i = 0; i < left_removed; ++i) {
        total -= score.front();
        score.pop_front();
    }

    for (int i = 0; i < right_removed; ++i) {
        total -= score.back();
        score.pop_back();
    }

    return (total / (double)score.size());
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L, H;
    deque<double> score;
    double total_score = input(L, H, score);

    cout << fixed; cout.precision(9);
    cout << simulate(L, H, total_score, score) << '\n';

    return 0;
}