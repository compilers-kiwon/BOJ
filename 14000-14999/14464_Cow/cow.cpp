#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> Cow; // <start_time, end_time>

vector<Cow> cow;
multiset<int> chicken;

void input(void) {
    int C, N;

    cin >> C >> N;

    for (int i = 1; i<= C; i++) {
        int T;
        cin >> T;
        chicken.insert(T);
    }

    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A >> B;
        cow.push_back({B, A});
    }

    sort(cow.begin(), cow.end());
}

int simulate(void) {
    int ret = 0;

    for (int i = 0; i < cow.size(); i++) {
        int start_time = cow[i].second;
        int end_time = cow[i].first;

        auto it = chicken.lower_bound(start_time);

        if (it != chicken.end() && *it <= end_time) {
            ret++, chicken.erase(it);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}