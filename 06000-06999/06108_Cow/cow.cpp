#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE (99+1)

int N, b[MAX_SIZE][MAX_SIZE];

void sort_row(void) {
    for (int row = 1; row <= N; row++) {
        sort(&b[row][1], &b[row][N+1]);
    }
}

void get_mid_of_each_row(vector<int>& mid) {
    for (int row = 1; row <= N; row++) {
        mid.push_back(b[row][(N+1)/2]);
    }
}

void input(void) {
    cin >> N;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            cin >> b[row][col];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> mid;

    input();
    sort_row();
    get_mid_of_each_row(mid);

    sort(mid.begin(), mid.end());
    cout << mid[N/2] << '\n';

    return 0;
}