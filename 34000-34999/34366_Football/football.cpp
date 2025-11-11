#include <iostream>

using namespace std;

#define INF (0x7FFFFFFF)

int get_month_score(int& max_game_score, int& min_game_score) {
    int S, sum;

    for (cin >> S, sum = 0; S > 0; S--) {
        int score;

        cin >> score;
        sum += score;

        max_game_score = max(max_game_score, score);
        min_game_score = min(min_game_score, score);
    }

    return sum;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    int max_game_score, min_game_score;
    int max_month_score, min_month_score;

    max_game_score = max_month_score = 0;
    min_game_score = min_month_score = INF;

    for (cin >> N; N > 0; N--) {
        int cur_month_score =
            get_month_score(max_game_score, min_game_score);
        
        max_month_score = max(max_month_score, cur_month_score);
        min_month_score = min(min_month_score, cur_month_score);
    }

    cout << max_game_score << '\n' << min_game_score << '\n'
            << max_month_score << '\n' << min_month_score << '\n';
    
    return 0;
}