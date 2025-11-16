#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    unordered_map<string, int> state;

    for (cin >> N; N > 0; N--) {
        string t, d;
        int num;

        cin >> t >> d >> num;
        state[t] += ((d=="IN")?1:-1) * num;
    }

    int sum = 0;

    for (auto it = state.begin(); it != state.end(); it++) {
        sum += it->second;
    }

    cout << ((sum==0)?"NO STRAGGLERS":to_string(sum)) << '\n';

    return 0;
}