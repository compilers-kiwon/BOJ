#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int simulate(const vector<int>& num) {
    vector<int> sum = num;

    for (; sum.size() > 1; sum.pop_back()) {
        for (int i = 1; i < sum.size(); ++i) {
            sum[i-1] += sum[i];
        }
    }

    return sum.front();
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, F;
    vector<int> num;

    cin >> N >> F;

    for (int i = 1; i <= N; ++i) {
        num.push_back(i);
    }

    do {
        if (simulate(num) == F) {
            break;
        }
    } while(next_permutation(num.begin(), num.end()));

    for (int i = 0; i < N; ++i) {
        cout << num[i] << ' ';
    }

    return 0;
}