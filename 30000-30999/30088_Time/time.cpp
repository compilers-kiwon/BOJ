#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int int64;

void input(vector<int64>& t) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int num;
        int64 sum;

        cin >> num, sum = 0LL;

        for (int j = 1; j <= num; ++j) {
            int64 m;
            cin >> m;
            sum += m;
        }

        t.push_back(sum);
    }

    sort(t.begin(), t.end());
}

int64 simulate(const vector<int64>& t) {
    int64 ret, prev_end_time;
    
    ret = prev_end_time = 0LL;

    for (int i = 0; i < t.size(); ++i) {
        prev_end_time += t[i];
        ret += prev_end_time;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int64> t;
    input(t);
    cout << simulate(t) << '\n';

    return 0;
}