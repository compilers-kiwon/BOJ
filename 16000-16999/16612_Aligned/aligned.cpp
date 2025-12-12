#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, L, total_length;

    cin >> n >> L, total_length = 0;

    for (int i = 1; i <= n; i++) {
        string w;
        cin >> w;
        total_length += w.length();
    }

    int num_of_pairs = n - 1;
    int num_of_required_spaces = L - total_length;

    if (num_of_pairs == 0) {
        cout << (num_of_required_spaces==0?"Yes":"No") << '\n';
    } else {
        if (num_of_required_spaces > 0 &&
                num_of_required_spaces % num_of_pairs == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}