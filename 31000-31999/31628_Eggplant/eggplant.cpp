#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE (10)

string grid[MAX_SIZE+1][MAX_SIZE+1];

void input(void) {
    for (int row = 1; row <= MAX_SIZE; row++) {
        for (int col = 1; col <= MAX_SIZE; col++) {
            cin>>grid[row][col];
        }
    }
}

bool check_row(int row) {
    for (int col = 1; col < MAX_SIZE; col++) {
        if (grid[row][col] != grid[row][col+1]) {
            return false;
        }
    }

    return true;
}

bool check_col(int col) {
    for (int row = 1; row < MAX_SIZE; row++) {
        if (grid[row][col] != grid[row+1][col]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    bool result = false;

    input();

    for (int p = 1; p <= MAX_SIZE && result != true; p++) {
        result = check_col(p) | check_row(p);
    }

    cout<<(result?1:0)<<'\n';
    return 0;
}