#include <iostream>

using namespace std;

#define MAX_NUM_OF_CUSTOMERS (50+1)
#define MAX_NUM_OF_PRODUCTS (100+1)

int N, X, Y;
int qx[MAX_NUM_OF_CUSTOMERS], qy[MAX_NUM_OF_CUSTOMERS];
int dp[MAX_NUM_OF_CUSTOMERS][MAX_NUM_OF_PRODUCTS][MAX_NUM_OF_PRODUCTS];

int simulate(int& last_customer) {
    int ret = MAX_NUM_OF_CUSTOMERS;

    for (int c = 1; c <= N; c++) {
        int x_quantity = min(X, qx[c]);
        int y_quantity = min(Y, qy[c]);

        dp[c][x_quantity][y_quantity] = 1;

        for (int x = 1; x <= X; x++) {
            for (int y = 1; y <= Y; y++) {
                if (dp[c-1][x][y] == 0) {
                    continue;
                }

                dp[c][x][y] = (dp[c][x][y]==0)?
                                dp[c-1][x][y]:
                                min(dp[c-1][x][y], dp[c][x][y]);

                int sum_of_x = min(X, x + x_quantity);
                int sum_of_y = min(Y, y + y_quantity);
                
                dp[c][sum_of_x][sum_of_y] = 
                    (dp[c][sum_of_x][sum_of_y]==0)?
                        dp[c-1][x][y] + 1:
                        min(dp[c][sum_of_x][sum_of_y], dp[c-1][x][y] + 1);
            }
        }

        if (dp[c][X][Y] != 0 && dp[c][X][Y] < ret) {
            ret = dp[c][X][Y], last_customer = c;
        }
    }

    return ((ret==MAX_NUM_OF_CUSTOMERS)?-1:ret);
}

void input(void) {
    cin >> N >> X >> Y;

    for (int i = 1; i <= N; i++) {
        cin >> qx[i] >> qy[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_customer, last_customer;

    input();
    num_of_customer = simulate(last_customer);

    if (num_of_customer == -1) {
        cout << "-1\n";
    } else {
        cout << num_of_customer << '\n' << last_customer << '\n';
    }

    return 0;
}