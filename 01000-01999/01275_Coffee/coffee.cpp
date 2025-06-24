#include <iostream>

#define MAX_SIZE (100000+1)
#define LEFT_CHILD(n) (2*(n))
#define RIGHT_CHILD(n) (LEFT_CHILD((n))+1)

typedef long long int int64;

int N, Q;
int64 num[MAX_SIZE], tree[MAX_SIZE*4];

void input(void) {
    std::cin>>N>>Q;

    for (int i = 1; i <= N; i++) {
        std::cin>>num[i];
    }
}

int64 build_tree(int start, int end, int node) {
    int64& ret = tree[node];

    if (start == end) {
        ret = num[start];
    } else {
        int mid = (start + end) / 2;
        ret = build_tree(start, mid, LEFT_CHILD(node))
                + build_tree(mid + 1, end, RIGHT_CHILD(node));
    }

    return ret;
}

void update_tree(int start, int end, int node, int idx, int64 val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;

        if (idx <= mid) {
            update_tree(start, mid, LEFT_CHILD(node), idx, val);
        } else {
            update_tree(mid + 1, end, RIGHT_CHILD(node), idx, val);
        }

        tree[node] = tree[LEFT_CHILD(node)] + tree[RIGHT_CHILD(node)];
    }
}

int64 query(int start, int end, int node, int left, int right) {
    if (start > right || end < left) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return (query(start, mid, LEFT_CHILD(node), left, right)
                + query(mid + 1, end, RIGHT_CHILD(node), left, right));
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    input();
    build_tree(1, N, 1);

    for (int i = 1; i <= Q; i++) {
        int x, y, a;
        int64 b;

        std::cin>>x>>y>>a>>b;
        std::cout<<query(1, N, 1, std::min(x, y), std::max(x, y))<<'\n';

        num[a] = b;
        update_tree(1, N, 1, a, b);
    }

    return 0;
}