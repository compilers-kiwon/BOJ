#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int prev_pos, cnt;
    string cowphabet, hummed;

    prev_pos = -1, cnt = 1;
    cin >> cowphabet >> hummed;

    for (int i = 0; i < hummed.length(); i++) {
        int cur_pos = cowphabet.find(hummed[i]);
        cnt += (cur_pos<=prev_pos)?1:0;
        prev_pos = cur_pos;
    }

    cout << cnt << '\n';

    return 0;
}