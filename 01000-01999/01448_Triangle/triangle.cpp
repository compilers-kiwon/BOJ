#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE (1000000+1)

int N, s[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int ans;

    cin >> N, ans = -1;

    for (int i = 1; i <= N; ++i) {
        cin >> s[i];
    }

    sort(&s[1], &s[N+1]);

    for (int i = N; i >= 3; --i) {
        int a = s[i-2];
        int b = s[i-1];
        int c = s[i];

        if ( c < a + b) {
            ans = a + b + c;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}