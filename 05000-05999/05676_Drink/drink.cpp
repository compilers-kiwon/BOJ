#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE (100000+1)
#define NONE ('+')

#define LEFT_CHILD(n) (2*(n))
#define RIGHT_CHILD(n) (LEFT_CHILD((n))+1)

#define determin_sign(num) (((num)>0)?'+':((num)<0)?'-':'0')

static inline char get_sign(char left, char right) {
    char ret;

    if (left == '0' || right == '0') {
        ret = '0';
    } else {
        ret = (left==right)?'+':'-';
    }

    return ret;
}

int N, K;
char X[MAX_SIZE], tree[MAX_SIZE*4];

void read_signs(void) {
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        X[i] = determin_sign(x);
    }
}

char build_tree(int tree_idx, int left, int right) {
    char& ret = tree[tree_idx];

    if (left == right) {
        ret = X[left];
    } else {
        int mid = (left + right) / 2;
        ret = get_sign(build_tree(LEFT_CHILD(tree_idx), left, mid),
                    build_tree(RIGHT_CHILD(tree_idx), mid + 1, right));
    }

    return ret;
}

char get(int tree_idx, int tree_left, int tree_right,
            int query_left, int query_right) {
    if (tree_right < query_left || query_right < tree_left) {
        return NONE;
    }

    if (query_left <= tree_left && tree_right <= query_right) {
        return tree[tree_idx];
    }

    int mid = (tree_left + tree_right) / 2;

    return get_sign(get(LEFT_CHILD(tree_idx), tree_left, mid, query_left, query_right),
                    get(RIGHT_CHILD(tree_idx), mid + 1, tree_right, query_left, query_right));
}

void update(int tree_idx, int left, int right, int num_idx, char s) {
    if (left == right) {
        tree[tree_idx] = X[num_idx] = s;
    } else {
        int mid = (left + right) / 2;

        if (num_idx <= mid) {
            update(LEFT_CHILD(tree_idx), left, mid, num_idx, s);
        } else {
            update(RIGHT_CHILD(tree_idx), mid + 1, right, num_idx, s);
        }

        tree[tree_idx] = get_sign(tree[LEFT_CHILD(tree_idx)], tree[RIGHT_CHILD(tree_idx)]);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;cin >> N >> K;) {
        string str;

        read_signs();
        build_tree(1, 1, N);

        for (int k = 1; k <= K; k++) {
            char op;
            int i, V, j;

            cin >> op;

            if (op == 'C') {
                cin >> i >> V;
                update(1, 1, N, i, determin_sign(V));
            } else {
                cin >> i >> j;
                str.push_back(get(1, 1, N, i, j));
            }
        }

        cout << str << '\n';
    }

    return 0;
}