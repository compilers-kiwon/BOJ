#include <iostream>

using namespace std;

#define MAX_SIZE (4)

const int calorie_table[MAX_SIZE+1][MAX_SIZE+1] = {
    {},
    {0, 461, 431, 420, 0},
    {0, 100, 57, 70, 0},
    {0, 130, 160, 118, 0},
    {0, 167, 266, 75, 0}
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum = 0;

    for (int i = 1; i <= MAX_SIZE; ++i) {
        int n;
        cin >> n;
        sum += calorie_table[i][n];
    }

    cout << "Your total Calorie count is " << sum << ".\n";

    return 0;
}