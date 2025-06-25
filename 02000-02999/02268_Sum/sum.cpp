#include <iostream>

#define MAX_SIZE (1000000+1)
#define NONE (0)

#define LEFT_CHILD(n) (2*(n))
#define RIGHT_CHILD(n) (LEFT_CHILD((n))+1)

typedef long long int int64;

int N, M;
int64 A[MAX_SIZE], tree[MAX_SIZE*4];

void modify(int node_idx, int left, int right, int num_idx, int64 val) {
    if (left == right) {
        tree[node_idx] = A[num_idx] = val;
    } else {
        int mid = (left + right) / 2;

        if (num_idx <= mid) {
            modify(LEFT_CHILD(node_idx), left, mid, num_idx, val);
        } else {
            modify(RIGHT_CHILD(node_idx), mid + 1, right, num_idx, val);
        }

        tree[node_idx] = tree[LEFT_CHILD(node_idx)] + tree[RIGHT_CHILD(node_idx)];
    }
}

int64 sum(int node_idx, int left, int right,
            int required_left, int required_right) {
    if (right < required_left || left > required_right) {
        return NONE;
    }

    if (required_left <= left && right <= required_right) {
        return tree[node_idx];
    }

    int mid = (left + right) / 2;

    return (sum(LEFT_CHILD(node_idx), left, mid, required_left, required_right)
            + sum(RIGHT_CHILD(node_idx), mid + 1, right, required_left, required_right));
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    std::cin>>N>>M;

    for (int m = 1; m <= M; m++) {
        int op, i, j;
        int64 k;

        std::cin>>op;

        if (op == 0) {  // Sum
            std::cin>>i>>j;
            std::cout<<sum(1, 1, N, std::min(i, j), std::max(i, j))<<'\n';
        } else {    // Modify
            std::cin>>i>>k;
            modify(1, 1, N, i, k);
        }
    }

    return 0;
}