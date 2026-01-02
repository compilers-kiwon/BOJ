#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int int64;

#define INF (1000000LL*1000000LL*1000000LL)

bool all_zero_num(const vector<int64>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0LL) {
            return false;
        }
    }

    return true;
}

void make_head_nonzero(vector<int64>& num) {
    for (int i = 0; i < num.size(); i++) {
        if (num[i] != 0LL) {
            swap(num[0], num[i]);
            break;
        }
    }
}

int64 get_num(const vector<int64>& num) {
    int64 ret = 0LL;

    for (int i = 0; i < num.size(); i++) {
        ret = ret * 10LL + num[i];
    }

    return ret;
}

int64 get_sum(vector<int64> num1, vector<int64> num2) {
    if (all_zero_num(num1) || all_zero_num(num2)) {
        return INF;
    }

    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());
    
    make_head_nonzero(num1);
    make_head_nonzero(num2);
    
    return (get_num(num1) + get_num(num2));
}

void dfs(int pos, const vector<int64>& digits,
            vector<int64>& num1, vector<int64>& num2, int64& min_sum) {
    if (pos == digits.size()) {
        if (!num1.empty() && !num2.empty()) {
            min_sum = min(min_sum, get_sum(num1, num2));
        }

        return;
    }

    num1.push_back(digits[pos]);
    dfs(pos + 1, digits, num1, num2, min_sum);
    num1.pop_back();

    num2.push_back(digits[pos]);
    dfs(pos + 1, digits, num1, num2, min_sum);
    num2.pop_back();
}

int64 simulate(const vector<int64>& digits) {
    int64 ret = INF;
    vector<int64> num1, num2;

    dfs(0, digits, num1, num2, ret);
    return ret;
}

bool input(vector<int64>& num) {
    int N;

    cin >> N;

    if (N == 0) {
        return false;
    }

    for (int i = 1; i <= N; i++) {
        int64 d;
        cin >> d;
        num.push_back(d);
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        vector<int64> num;

        if (input(num) == false) {
            break;
        }

        cout << simulate(num) << '\n';
    }

    return 0;
}