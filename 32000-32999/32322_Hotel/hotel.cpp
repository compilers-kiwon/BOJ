#include <iostream>

using namespace std;

#define MAX_SIZE (500000+1)
#define LEFT_CHILD(n) ((n)*2)
#define RIGHT_CHILD(n) (LEFT_CHILD((n))+1)

const int NONE = 0;
const int AVAILABLE = 1;
const int RESERVED = 0;

int tree[4*MAX_SIZE];

int build_tree(int node, int left, int right) {
    int& ret = tree[node];

    if (left == right) {
        ret = AVAILABLE;
    } else {
        int mid = (left + right) / 2;
        ret = build_tree(LEFT_CHILD(node), left, mid)
                + build_tree(RIGHT_CHILD(node), mid + 1, right);
    }

    return ret;
}

int get(int node, int left, int right, int requested_left, int requested_right) {
    if (left > requested_right || right < requested_left) {
        return NONE;
    }

    if (requested_left <= left && right <= requested_right) {
        return tree[node];
    }

    int mid = (left + right) / 2;

    return get(LEFT_CHILD(node), left, mid, requested_left, requested_right)
            + get(RIGHT_CHILD(node), mid + 1, right, requested_left, requested_right);
}

void update(int node, int left, int right, int idx) {
    if (left == right) {
        tree[node] = RESERVED;
    } else {
        int mid = (left + right) / 2;

        if (idx <= mid) {
            update(LEFT_CHILD(node), left, mid, idx);
        } else {
            update(RIGHT_CHILD(node), mid + 1, right, idx);
        }

        tree[node] = tree[LEFT_CHILD(node)] + tree[RIGHT_CHILD(node)];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, t;

    cin >> n >> t;
    build_tree(1, 1, n);

    for (; t > 0; t--) {
        char c;

        cin >> c;

        if (c == 'A') {
            int i, j;
            cin >> i >> j;
            cout << get(1, 1, n, i, j) << '\n';
        } else {
            int r;
            cin >> r;
            update(1, 1, n, r);
        }
    }

    return 0;
}