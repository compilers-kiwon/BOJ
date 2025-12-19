#include <iostream>
#include <cmath>

using namespace std;

#define NUM_OF_SQAURES (8)
#define SIZE_OF_SQUARE (3)

const int magic_square[8][SIZE_OF_SQUARE][SIZE_OF_SQUARE] = {
    {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    },
    {
        {4, 3, 8},
        {9, 5, 1},
        {2, 7, 6}
    },
    {
        {2, 9, 4},
        {7, 5, 3},
        {6, 1, 8}
    },
    {
        {6, 7, 2},
        {1, 5, 9},
        {8, 3, 4}
    },
    {
        {6, 1, 8},
        {7, 5, 3},
        {2, 9, 4}
    },
    {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    },
    {
        {8, 3, 4},
        {1, 5, 9},
        {6, 7, 2}
    },
    {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    }
};

int get_cost(int A[][SIZE_OF_SQUARE], int ptr) {
    int ret = 0;

    for (int row = 0; row < SIZE_OF_SQUARE; row++) {
        for (int col = 0; col < SIZE_OF_SQUARE; col++) {
            ret += abs(A[row][col] - magic_square[ptr][row][col]);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A[SIZE_OF_SQUARE][SIZE_OF_SQUARE];

    for (int row = 0; row < SIZE_OF_SQUARE; row++) {
        for (int col = 0; col < SIZE_OF_SQUARE; col++) {
            cin >> A[row][col];
        }
    }

    int min_cost = 0x7FFFFFFF;

    for (int i = 0; i < NUM_OF_SQAURES; i++) {
        min_cost = min(min_cost, get_cost(A, i));
    }

    cout << min_cost << '\n';
    return 0;
}