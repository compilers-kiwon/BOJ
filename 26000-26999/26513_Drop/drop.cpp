#include <iostream>
#include <string>

using namespace std;

void get_logs(int num_of_logs, int height,
                int& safe, int& broken) {
    int upper_bound_for_safe = 1;
    int lower_bound_for_broken = height;

    for (int i = 1; i <= num_of_logs; ++i) {
        int floor;
        string result;

        cin >> floor >> result;

        if (result == "SAFE") {
            upper_bound_for_safe = max(upper_bound_for_safe, floor);
        } else {
            lower_bound_for_broken = min(lower_bound_for_broken, floor);
        }
    }

    safe = upper_bound_for_safe + 1;
    broken = lower_bound_for_broken - 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int n, k;

        cin >> n >> k;

        if (n == 0 && k == 0) {
            break;
        }

        int safe, broken;
        get_logs(n, k, safe, broken);
        cout << safe << ' ' << broken << '\n';
    }

    return 0;
}