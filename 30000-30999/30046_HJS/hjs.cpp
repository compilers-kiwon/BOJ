#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_SIZE (3)

int N;
string num[MAX_SIZE];

bool check_order(const string& sorted, int small, int big) {
    int pos;
    const string& small_num = num[small];
    const string& big_num = num[big];

    for (pos = 0; pos <= N; pos++) {
        if (small_num[pos] != big_num[pos]) {
            break;
        }
    }

    if (pos == N) {
        return false;
    }

    return (sorted.find(small_num[pos]) < sorted.find(big_num[pos]));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string digit = "HJS";

    cin >> N;
    sort(digit.begin(), digit.end());

    for (int i = 0; i < MAX_SIZE;i++) {
        cin >> num[i];
    }

    do {
        if (check_order(digit, 0, 1) && check_order(digit, 1, 2)) {
            cout << "HJS! HJS! HJS!\n";
            return 0;
        }
    } while (next_permutation(digit.begin(), digit.end()));

    cout << "Hmm...\n";

    return 0;
}