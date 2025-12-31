#include <iostream>

using namespace std;

typedef long long int int64;

#define MAX_SIZE (100000+2)

int N;
int64 H[MAX_SIZE];
int64 sum1[MAX_SIZE], sum2[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
}

void get_sum(void) {
    for (int i = 1; i <= N; i++) {
        sum1[i] = sum1[i-1] + H[i];
    }

    for (int i = N; i >= 1; i--) {
        sum2[i] = sum2[i+1] + H[i];
    }
}

int64 simulate(void) {
    int64 ret = 0LL;
    int64 bee1, bee2;

    bee1 = sum1[N] - H[1];
    
    for (int i = 2; i <= N - 1; i++) {
        bee2 = sum1[N] - sum1[i];
        ret = max(ret, bee1 - H[i] + bee2);
    }

    for (int i = 2; i <= N - 1; i++) {
        bee1 = sum1[i] - H[1];
        bee2 = sum2[i] - H[N];
        ret = max(ret, bee1 + bee2);
    }

    bee2 = sum2[1] - H[N];

    for (int i = N - 1; i >= 2; i--) {
        bee1 = sum2[1] - sum2[i];
        ret = max(ret, bee2 - H[i] + bee1);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_sum();
    cout << simulate() << '\n';

    return 0;
}