#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_SIZE (1000000+1)

typedef long long int int64;

int64 input(priority_queue<int64>& income) {
    int n;
    int64 ret;

    cin >> n, ret = 0LL;

    for (int i = 1; i <= n; ++i) {
        int64 m;
        cin >> m;
        income.push(m), ret += m;
    }

    return ret;
}

double simulate(int num_of_persons, int64 sum,
                    priority_queue<int64>& income) {
    int counted = 0;
    int64 cur = 0LL;
    double ret = 0.0;

    for (; !income.empty(); income.pop()) {
        ++counted, cur += income.top();

        double x = (double)(counted * 100) / (double)num_of_persons;
        double y = (double)cur * 100.0 / (double)sum;

        ret = max(ret, y - x);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int64> income;
    int64 sum = input(income);

    cout << fixed; cout.precision(6);
    cout << simulate(income.size(), sum, income) << '\n';

    return 0;
}