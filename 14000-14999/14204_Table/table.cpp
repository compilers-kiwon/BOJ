#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE (50+1)

int N, M, arr[MAX_SIZE][MAX_SIZE];

void input(void) {
    cin >> N >> M;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            cin >> arr[row][col];
        }
    }
}

bool sort_row(void) {
    vector<pair<int, vector<int>>> v;

    for (int row = 1; row <= N; row++) {
        int min_num = (N * M) + 1;
        pair<int, vector<int>> desc;

        for (int col = 1; col <= M; col++) {
            desc.second.push_back(arr[row][col]);
            min_num = min(min_num, arr[row][col]);
        }

        desc.first = min_num;
        v.push_back(desc);
    }

    sort(v.begin(), v.end());

    int expected = 1;

    for (int row = 1; row <= N; row++) {
        if (v[row-1].first != expected) {
            return false;
        }

        for (int col = 1; col <= M; col++) {
            arr[row][col] = v[row-1].second[col-1];
        }

        expected += M;
    }

    return true;
}

void swap_col(int c1, int c2) {
    for (int row = 1; row <= N; row++) {
        swap(arr[row][c1], arr[row][c2]);
    }
}

bool check_arr(void) {
    int expected = 1;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            if (arr[row][col] != expected++) {
                return false;
            }
        }
    }

    return true;
}

bool sort_col(void) {
    for (int c1 = 1; c1 <= M - 1; c1++) {
        int min_idx = c1;

        for (int c2 = c1 + 1; c2 <= M; c2++) {
            if (arr[1][min_idx] > arr[1][c2]) {
                min_idx = c2;
            }
        }

        if (c1 != min_idx) {
            swap_col(c1, min_idx);
        }
    }

    return check_arr();
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    if (sort_row() == false || sort_col() == false) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }

    return 0;
}