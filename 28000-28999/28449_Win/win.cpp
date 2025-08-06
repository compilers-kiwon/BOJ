#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long int int64;

int64 input(vector<int>& a, vector<int>& b) {
    int N, M;
    int64 ret;
    unordered_map<int, int64> cnt;

    ret = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        a.push_back(n), ++cnt[n];
    }

    for (int i = 1; i <= M; i++) {
        int n;
        cin >> n;

        b.push_back(n);
        
        if (cnt.find(n) != cnt.end()) {
            ret += cnt[n];
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return ret;
}

int64 simulate(vector<int>& t1, vector<int>& t2) {
    int64 ret = 0;

    for (int i = 0; i < t1.size(); i++) {
        auto it = lower_bound(t2.begin(), t2.end(), t1[i]);
        ret += (int64)(it - t2.begin());
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> a, b;
    int64 tie= input(a, b);

    cout << simulate(a, b) << ' ' <<
            simulate(b, a) << ' ' << tie << '\n';

    return 0;
}