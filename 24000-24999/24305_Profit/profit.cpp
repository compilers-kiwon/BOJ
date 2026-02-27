#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> State; // <profit, day>

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> profit = {-1};

    cin >> N;

    vector<State> s = {{-1, 0}};
    vector<int> prev_day(N + 1);

    for (int i = 1; i <= N; ++i) {
        int p;
        cin >> p;
        profit.push_back(p);
    }

    profit.push_back(0);

    for (int d = 1; d < profit.size(); ++d) {
        int cur_profit = profit[d];
        
        for (; s.back().first >= cur_profit; s.pop_back()) {
            auto tail = s.rbegin();
            prev_day[tail->second] = (tail + 1)->second;
        }

        s.push_back({cur_profit, d});
    }

    for (int i = 1; i <= N; ++i) {
        cout << prev_day[i] << ' ';
    }

    cout << '\n';
    return 0;
}