#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Rule;

const vector<Rule> ru = {
    {1000000, 20}, {500000, 15}, {100000, 10}, {0, 5}
};

#define calculate(q,r) ((q)/100*(r))

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 0; i < ru.size(); i++) {
        if (N >= ru[i].first) {
            cout << calculate(N, ru[i].second) << ' '
                    << N - calculate(N, ru[i].second) << '\n';
            break;
        }
    }

    return 0;
}