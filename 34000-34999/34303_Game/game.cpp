#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef long long int int64;

unordered_map<string, int64> event = {
    {"COIN", 2}, {"DIE", 6}, {"CARDS", 52}
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    int64 total, L;

    for (cin >> N, total = 1; N > 0; N--) {
        string s;
        cin >> s;
        total *= event[s];
    }

    cin >> L;
    cout << (total - 1) * L << '\n';

    return 0;
}