#include <iostream>

#define MAX_SIZE (100000+1)
#define LEFT_CHILD(n) (2*(n))
#define RIGHT_CHILD(n) (LEFT_CHILD((n))+1)

int N, M, A[MAX_SIZE], tree[MAX_SIZE*4];

int build(int node_idx, int left, int right) {
    int& ret = tree[node_idx];

    if (left == right) {
        ret = left;
    } else {
        int mid = (left + right) / 2;
        int left_min_idx = build(LEFT_CHILD(node_idx), left, mid);
        int right_min_idx = build(RIGHT_CHILD(node_idx), mid + 1, right);

        if (A[left_min_idx] <=
                A[right_min_idx]) {
            ret = left_min_idx;
        } else {
            ret = right_min_idx;
        }
    }

    return ret;
}

void update(int node_idx, int left, int right, int num_idx, int val) {
    if (left == right) {
        A[num_idx] = val;
        tree[node_idx] = num_idx;
    } else {
        int mid = (left + right) / 2;

        if (num_idx <= mid) {
            update(LEFT_CHILD(node_idx), left, mid, num_idx, val);
        } else {
            update(RIGHT_CHILD(node_idx), mid + 1, right, num_idx, val);
        }

        if (A[tree[LEFT_CHILD(node_idx)]] <= A[tree[RIGHT_CHILD(node_idx)]]) {
            tree[node_idx] = tree[LEFT_CHILD(node_idx)];
        } else {
            tree[node_idx] = tree[RIGHT_CHILD(node_idx)];
        }
    }
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    std::cin>>N;

    for (int n = 1; n <= N; n++) {
        std::cin>>A[n];
    }

    build(1, 1, N);
    
    std::cin>>M;

    for (int m = 1; m <= M; m++) {
        int q, i, v;

        std::cin>>q;

        if (q == 1) {
            std::cin>>i>>v;
            update(1, 1, N, i, v);
        } else { // q == 2
            std::cout<<tree[1]<<'\n';
        }
    }

    return 0;
}