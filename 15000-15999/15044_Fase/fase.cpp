#include <iostream>
#include <map>

using namespace std;

int simulate(const map<int, int>& result, int min_num) {
    int ret = 0;

    for (auto rit = result.rbegin(); rit != result.rend() && ret < min_num; ++rit) {
        ret += rit->second;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(NULL);

    int N, K;
    map<int, int> result;

    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        int score;
        cin >> score;
        ++result[score];
    }

    cout << simulate(result, K) << '\n';

    return 0;
}