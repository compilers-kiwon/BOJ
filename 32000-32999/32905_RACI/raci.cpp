#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m;
    bool is_correct;

    cin >> n >> m, is_correct = true;

    for (int row = 1; row <= n; row++) {
        int num_of_accountable = 0;
        for (int col = 1; col <= m; col++) {
            char c;
            cin >> c;
            num_of_accountable += (c=='A')?1:0;
        }

        is_correct &= (num_of_accountable == 1);
    }

    cout << (is_correct?"Yes":"No") << '\n';
    return 0;
}