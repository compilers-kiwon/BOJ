#include <iostream>
#include <climits>

#define MAX_SIZE (100000+1)
#define LEFT_CHILD(n) (2*(n))
#define RIGHT_CHILD(n) (LEFT_CHILD((n))+1)

int N, M, A[MAX_SIZE+1], tree[MAX_SIZE*4];

void input(void) {
    std::cin>>N;

    for (int i = 1; i <= N; i++) {
        std::cin>>A[i];
    }

    A[MAX_SIZE] = INT_MAX;
}

int build_tree(int node_idx, int left_pos, int right_pos) {
    int& ret = tree[node_idx];

    if (left_pos == right_pos) {
        ret = left_pos;
    } else {
        int mid_pos = (left_pos + right_pos) / 2;
        int left_min_pos = build_tree(LEFT_CHILD(node_idx), left_pos, mid_pos);
        int right_min_pos = build_tree(RIGHT_CHILD(node_idx), mid_pos + 1, right_pos);

        if (A[left_min_pos] <= A[right_min_pos]) {
            ret = left_min_pos;
        } else {
            ret = right_min_pos;
        }
    }

    return ret;
}

void update_tree(int node_idx, int left_pos, int right_pos, int num_pos, int val) {
    if (left_pos == right_pos) {
        tree[node_idx] = num_pos; 
        A[num_pos] = val;
    } else {
        int mid_pos = (left_pos + right_pos) / 2;

        if (num_pos <= mid_pos) {
            update_tree(LEFT_CHILD(node_idx), left_pos, mid_pos, num_pos, val);
        } else {
            update_tree(RIGHT_CHILD(node_idx), mid_pos + 1, right_pos, num_pos, val);
        }

        if (A[tree[LEFT_CHILD(node_idx)]] <= A[tree[RIGHT_CHILD(node_idx)]]) {
            tree[node_idx] = tree[LEFT_CHILD(node_idx)];
        } else {
            tree[node_idx] = tree[RIGHT_CHILD(node_idx)];
        }
    }
}

int query(int node_idx, int left_pos, int right_pos, int query_left, int query_right) {
    if (query_right < left_pos || right_pos < query_left) {
        return MAX_SIZE;
    }

    if (query_left <= left_pos && right_pos <= query_right) {
        return tree[node_idx];
    }

    int left_min_pos, right_min_pos, mid_pos;
    
    mid_pos = (left_pos + right_pos) / 2;
    left_min_pos = query(LEFT_CHILD(node_idx), left_pos, mid_pos, query_left, query_right);
    right_min_pos = query(RIGHT_CHILD(node_idx), mid_pos + 1, right_pos, query_left, query_right);

    return (A[left_min_pos] <= A[right_min_pos])?left_min_pos:right_min_pos;
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    input();
    build_tree(1, 1, N);

    std::cin>>M;

    for (int m = 1; m <= M; m++) {
        int op, i, v, j;

        std::cin>>op;

        if (op == 1) {
            std::cin>>i>>v;
            update_tree(1, 1, N, i, v);
        } else { // op == 2
            std::cin>>i>>j;
            std::cout<<query(1, 1, N, i, j)<<'\n';
        }
    }

    return 0;
}