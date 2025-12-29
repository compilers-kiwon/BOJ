#include <iostream>

using namespace std;

#define MAX_SIZE (200+1)
#define MAX_COST (300000)
#define MOD(n) ((n)%1000000007LL)
#define get_cost(a,m) (6LL*((a)/250LL)*(m/15LL))

typedef long long int int64;

int64 a[MAX_SIZE], m[MAX_SIZE];
int64 c1, c2, cost[MAX_SIZE][MAX_COST+1];

int input(void) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> m[i];
    }

    cin >> c1 >> c2;

    return n;
}

int64 simulate(int num_of_computers) {
    for (int i = 1; i <= num_of_computers; i++) {
        int64 cur_cost = get_cost(a[i], m[i]);

        if (cur_cost <= (int64)MAX_COST) {
            cost[i][cur_cost] = 1;
        }

        for (int c = 1; c <= MAX_COST; c++) {
            cost[i][c] = MOD(cost[i][c] + cost[i-1][c]);

            if (c + cur_cost <= (int64)MAX_COST) {
                cost[i][c+cur_cost] = MOD(cost[i][c+cur_cost] + cost[i-1][c]);
            }
        }
    }

    int64 ret = 0;

    for (int64 c = c1; c <= c2; c++) {
        ret = MOD(ret + cost[num_of_computers][c]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n = input();
    cout << simulate(n) << '\n';

    return 0;
}