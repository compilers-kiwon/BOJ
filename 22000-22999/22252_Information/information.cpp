#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

typedef long long int int64;

unordered_map<string, priority_queue<int64>> state;

int64 pay_for_information(void) {
    int b;
    int64 ret;
    string name;

    cin >> name >> b, ret = 0LL;

    for (int i = 1; i <= b && !state[name].empty(); ++i) {
        ret += state[name].top();
        state[name].pop();
    }

    return ret;
}

void get_information(void) {
    int k;
    string name;

    cin >> name >> k;

    for (int i = 1; i <= k; ++i) {
        int64 C;
        cin >> C;
        state[name].push(C);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q;
    int64 sum;

    for (cin >> Q, sum = 0LL; Q > 0; --Q) {
        int q;
        
        cin >> q;

        switch (q) {
            case 1: get_information(); break;
            case 2: sum += pay_for_information(); break;
            default: /*do nothing*/; break;
        }
    }

    cout << sum << '\n';

    return 0;
}