#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    unordered_map<int, int> cnt;

    cin >> N;

    for (int i = 1; i <= 2 * N; ++i) {
        int a;
        cin >> a;

        if (++cnt[a] > 2) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}