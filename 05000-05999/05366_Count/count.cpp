#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int input(vector<string>& order,
            unordered_map<string, int>& cnt) {
    int ret;

    for (ret = 0;; ++ ret) {
        string s;

        getline(cin, s);

        if (s == "0") {
            break;
        }

        if (cnt.find(s) == cnt.end()) {
            order.push_back(s);
        }

        ++cnt[s];
    }

    return ret;
}

void print(int total, const vector<string>& order,
            unordered_map<string, int>& cnt) {
    for (int i = 0; i < order.size(); ++i) {
        cout << order[i] << ": " << cnt[order[i]] << '\n';
    }

    cout << "Grand Total: " << total << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int total;
    vector<string> order;
    unordered_map<string, int> cnt;

    total = input(order, cnt);
    print(total, order, cnt);

    return 0;
}