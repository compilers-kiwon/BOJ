#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_WEIGHT (10000+1)

bool used[MAX_WEIGHT], pow_2[MAX_WEIGHT*2];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    vector<int> sum, ans;

    cin >> n;

    for (int i = 2; i <= (2 * n); i *= 2) {
        pow_2[i] = true;
    }

    for (int lead = n; lead >= 1; lead--) {
        for (int tin = n; tin >= 1; tin--) {
            if (used[tin] == false && pow_2[lead+tin] == true) {
                used[tin] = true;
                ans.push_back(tin);
                break;
            }
        }
    }

    for (auto it = ans.rbegin(); it != ans.rend(); it++){
        cout << *it << '\n';
    }

    return 0;
}