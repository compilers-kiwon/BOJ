#include <iostream>
#include <climits>

#define MAX_SIZE (100000+1)
#define NONE (INT_MAX)

#define LEFT_CHILD(n) (2*(n))
#define RIGHT_CHILD(n) (LEFT_CHILD((n))+1)

int N, M, A[MAX_SIZE], tree[MAX_SIZE*4];

int build(int node_idx, int left, int right) {
    int& ret = tree[node_idx];

    if (left == right) {
        ret = A[left];
    } else {
        int mid = (left + right) / 2;
        ret = std::min(build(LEFT_CHILD(node_idx), left, mid),
                    build(RIGHT_CHILD(node_idx), mid + 1, right));
    }

    return ret;
}

int get(int node_idx, int left, int right,
            int required_left, int required_right) {
    if (required_left > right || required_right < left) {
        return NONE;
    }

    if (required_left <= left && right <= required_right) {
        return tree[node_idx];
    }

    int mid = (left + right) / 2;

    return std::min(get(LEFT_CHILD(node_idx), left, mid, required_left, required_right),
                get(RIGHT_CHILD(node_idx), mid + 1, right, required_left, required_right));
}

void update(int node_idx, int left, int right, int num_idx, int val) {
    if (left == right) {
        tree[node_idx] = A[num_idx] = val;
    } else {
        int mid = (left + right) / 2;

        if (num_idx <= mid) {
            update(LEFT_CHILD(node_idx), left, mid, num_idx, val);
        } else {
            update(RIGHT_CHILD(node_idx), mid + 1, right, num_idx, val);
        }

        tree[node_idx] = std::min(tree[LEFT_CHILD(node_idx)], tree[RIGHT_CHILD(node_idx)]);
    }
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    std::cin>>N;
    
    for (int i = 1; i <= N; i++) {
        std::cin>>A[i];
    }

    build(1, 1, N);
    
    std::cin>>M;

    for (int m = 1; m <= M; m++) {
        int op, i, v, j;

        std::cin>>op;

        if (op == 1) {
            std::cin>>i>>v;
            update(1, 1, N, i, v);
        } else { // op == 2
            std::cin>>i>>j;
            std::cout<<get(1, 1, N, i, j)<<'\n';
        }
    }

    return 0;
}