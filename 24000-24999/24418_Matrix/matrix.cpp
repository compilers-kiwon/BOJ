#include <iostream>

using namespace std;

#define MAX_SIZE (15+1)

int n, m[MAX_SIZE][MAX_SIZE];

int matrix_path_rec(int row, int col) {
    if ((row == 0) || (col == 0)) {
        return 0;
    }

    return matrix_path_rec(row - 1, col) + matrix_path_rec(row, col - 1) + 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    cin>>n;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            cin>>m[row][col];
        }
    }

    cout<<(matrix_path_rec(n,n) + 1)<<' '<<(n * n)<<'\n';

    return 0;
}