#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE (1000000+1)

int N, A[MAX_SIZE], B[MAX_SIZE];

void input(void) {
    int X, pos;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];

        if (A[i] == -1) {
            pos = i;
        }
    }

    cin >> A[pos];
}

void simulate(int cur_node, int left, int right) {
    if (left == right) {
        B[cur_node] = A[left];
        return;
    }

    int mid = (left + right) / 2;
    
    B[cur_node] = A[mid];
    simulate(cur_node * 2, left, mid - 1);
    simulate(cur_node * 2 + 1, mid + 1, right);
}

void print(int node) {
    int left = node * 2;
    int right = left + 1;

    if (left <= N) {
        print(left);
    }

    if (right <= N) {
        print(right);
    }

    cout << B[node] << ' ';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    sort(&A[1], &A[N+1]);
    simulate(1, 1, N);
    print(1);

    return 0;
}