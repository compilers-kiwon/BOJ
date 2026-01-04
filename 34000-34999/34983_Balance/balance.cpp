#include <iostream>

using namespace std;

#define MAX_SIZE (200+1)

int N, rI, rG;
int I[MAX_SIZE], G[MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][MAX_SIZE];

void input(void) {
    cin >> N >> rI >> rG;

    for (int i = 1; i <= N; i++) {
        cin >> I[i] >> G[i];
    }

    for (int p = 0; p <= N; p++) {
        for (int i = 0; i <= rI; i++) {
            fill(&dp[p][i][0], &dp[p][i][rG+1], MAX_SIZE);
        }
    }
}

int simulate(void) {
    for (int p = 1; p <= N; p++) {
        int r_i = min(I[p], rI);
        int r_g = min(G[p], rG);

        dp[p][r_i][r_g] = 1;

        for (int i = 0; i <= rI; i++) {
            for (int g = 0; g <= rG; g++) {
                if (dp[p-1][i][g] == MAX_SIZE) {
                    continue;
                }

                dp[p][i][g] = min(dp[p][i][g], dp[p-1][i][g]);

                int inc_i = min(i + r_i, rI);
                int inc_g = min(g + r_g, rG);

                dp[p][inc_i][inc_g] = min(dp[p][inc_i][inc_g], dp[p-1][i][g] + 1);
            }
        }
    }

    return ((dp[N][rI][rG]==MAX_SIZE)?-1:dp[N][rI][rG]);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}