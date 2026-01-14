#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, vector<int>& answer,
            vector<int>& selected, int cur_pos, int target) {
    if (target == 0) {
        answer = selected;
        return;
    }

    if (cur_pos == numbers.size()) {
        return;
    }

    int cur_num = numbers[cur_pos];

    if (cur_num > target) {
        return;
    }

    selected.push_back(cur_num);
    dfs(numbers, answer, selected,
            cur_pos + 1, target - cur_num);
    selected.pop_back();

    dfs(numbers, answer, selected, cur_pos + 1, target);
}

int input(vector<int>& numbers) {
    int t, n;

    for (cin >> t >> n; n > 0; n--) {
        int c;

        cin >> c;

        if (c <= t) {
            numbers.push_back(c);
        }
    }

    return t;
}

void simulate(const vector<int>& numbers, int target, vector<int>& answer) {
    vector<int> selected;
    dfs(numbers, answer, selected, 0, target);
}

void print_answer(const vector<int>& answer) {
    if (answer.empty()) {
        cout << "No move found.\n";
        return;
    }

    cout << "The best move is: ";

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ((i==answer.size()-1)?'\n':' ');
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        int target;
        vector<int> numbers, answer;

        target = input(numbers);
        simulate(numbers, target, answer);
        print_answer(answer);
    }

    return 0;
}