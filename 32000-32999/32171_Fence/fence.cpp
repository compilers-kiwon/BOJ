#include <iostream>

using namespace std;

#define MAX_LEN (10)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    int prev_left, prev_right, prev_bottom, prev_top;

    cin >> N;
    prev_left = prev_bottom = MAX_LEN;
    prev_right = prev_top = -MAX_LEN;

    for (int i = 1; i <= N; ++i) {
        int a, b, c, d, cost;
        
        cin >> a >> b >> c >> d;

        int cur_left = min(a, prev_left);
        int cur_bottom = min(b, prev_bottom);
        int cur_right = max(c, prev_right);
        int cur_top = max(d, prev_top);

        cost = 2 * ((cur_right - cur_left) + (cur_top - cur_bottom));

        prev_left = cur_left, prev_bottom = cur_bottom;
        prev_right = cur_right, prev_top = cur_top;

        cout << cost << '\n';
    }

    return 0;
}