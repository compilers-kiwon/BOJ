#include <iostream>
#include <vector>
#include <map>

using namespace std;

int input(vector<int>& my, map<int, int>& opponent) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        my.push_back(n);
    }

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        opponent[n]++;
    }

    return N;
}

int simulate(vector<int>& my, map<int, int>& opponent) {
    int ret = 0;

    for (int i = 0; i < my.size(); i++) {
        auto it = opponent.upper_bound(my[i]);

        if (it == opponent.end()) {
            continue;
        }

        ret++;

        if (--(it->second) == 0) {
            opponent.erase(it);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_cards, my_score;
    vector<int> my_cards;
    map<int, int> opponent_cards;

    num_of_cards = input(my_cards, opponent_cards);
    my_score = simulate(my_cards, opponent_cards);

    if (my_score >= ((num_of_cards + 1)/2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}