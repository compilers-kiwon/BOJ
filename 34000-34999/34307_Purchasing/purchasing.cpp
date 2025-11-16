#include <iostream>

using namespace std;

typedef long long int int64;

#define MAX_SIZE (100000+1)

int N;
int64 p[MAX_SIZE], sum[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
}

int64 simulate(int interval) {
    int64 ret = 0;
    int end = (N / interval) * interval;

    for (int i = 1; i <= end; i += interval) {
        ret += p[i] * (int64)interval;
    }

    if (end < N) {
        ret += p[end+1] * (int64)(N - end);
    }
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int64 min_budget = sum[N];

    for (int i = 2; i <= N; i++) {
        min_budget = min(min_budget, simulate(i));
    }

    cout << min_budget << '\n';

    return 0;
}