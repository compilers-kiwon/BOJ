#include <iostream>
#include <vector>

using namespace std;

typedef long long int int64;

#define MAX_NUM (2147483647LL)

void init(vector<int64>& numbers) {
    for (int64 i = 1LL; i <= MAX_NUM; i *= 3LL) {
        numbers.push_back(i);
    }
}

bool dfs(const vector<int64>& numbers,
            int cur_idx, int64 cur_sum, int64 target) {
    if (cur_sum == target) {
        return true;
    }

    if (cur_idx == numbers.size() || cur_sum > target) {
        return false;
    }

    if (dfs(numbers, cur_idx + 1, cur_sum, target) == true ||
            dfs(numbers, cur_idx + 1, cur_sum + numbers[cur_idx], target) == true) {
        return true;
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N;
    vector<int64> numbers;

    cin >> N, init(numbers);

    if (N == 0LL) {
        cout << "NO\n";
    } else {
        cout << (dfs(numbers, 0, 0LL, N)?"YES":"NO") << '\n';
    }

    return 0;
}