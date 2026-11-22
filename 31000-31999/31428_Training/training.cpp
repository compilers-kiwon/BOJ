#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char c;
    int N, cnt[0x100];
    cin >> N, fill(cnt, cnt + 0x100, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> c;
        ++cnt[c];
    }

    cin >> c;
    cout << cnt[c] << '\n';
    
    return 0;
}