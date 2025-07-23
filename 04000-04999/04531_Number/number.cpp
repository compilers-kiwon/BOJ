#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, val[0x100];

    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;

    cin >> N;

    for (int n = 1; n <= N; n++) {
        int sum;
        string num;

        cin >> num;
        sum = val[num.front()];

        for (int i = 1; i < num.length(); i++) {
            int prev = val[num[i-1]];
            int cur = val[num[i]];

            if (cur > prev) {
                sum += ((-2) * prev) + cur;
            } else {
                sum += cur;
            }
        }

        cout << sum << '\n';
    }

    return 0;
}