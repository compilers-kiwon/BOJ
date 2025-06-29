#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<tuple<int, int, int>> op;

string input(void) {
    int N, M;
    string ret;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        int A;
        cin>>A;
        ret += to_string(A-1);
    }

    cin>>M;

    for (int i = 1; i <= M; i++) {
        int l, r, c;
        cin>>l>>r>>c;
        op.push_back({l - 1, r - 1, c});
    }

    return ret;
}

int simulate(string& str) {
    int ret = -1;
    unordered_map<string, int> dp;
    priority_queue<pair<int, string>> pq;

    dp[str] = 0;
    pq.push({0, str});
    sort(str.begin(), str.end());

    for (; !pq.empty(); pq.pop()) {
        int cur_cost = -pq.top().first;
        string cur_arr = pq.top().second;

        if (cur_arr == str) {
            ret = cur_cost;
            break;
        }

        for (int i = 0; i < op.size(); i++) {
            string tmp = cur_arr;
            auto [l, r, c] = op[i];

            swap(tmp[l], tmp[r]);

            if (dp.find(tmp) == dp.end() || (cur_cost + c) < dp[tmp]) {
                dp[tmp] = cur_cost + c;
                pq.push({-(cur_cost + c), tmp});
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string in = input();
    cout<<simulate(in)<<'\n';

    return 0;
}