#include <iostream>

using namespace std;

#define MAX_SIZE (1000+1)

int preorder[MAX_SIZE];
int inorder_pos[MAX_SIZE];
int left_child[MAX_SIZE], right_child[MAX_SIZE];

int build_tree(int preorder_root, int left, int right) {
    int ret = preorder[preorder_root];
    int mid = inorder_pos[ret];

    int num_of_left = mid - left;
    int num_of_right = right - mid;

    if (num_of_left > 0) {
        left_child[ret] = build_tree(preorder_root + 1, left, mid - 1);
    }

    if (num_of_right > 0) {
        right_child[ret] = build_tree(preorder_root + 1 + num_of_left, mid + 1, right);
    }

    return ret;
}

void postorder(int v, char c) {
    if (left_child[v] != 0) {
        postorder(left_child[v], ' ');
    }

    if (right_child[v] != 0) {
        postorder(right_child[v], ' ');
    }

    cout << v << c;
}

int input(void) {
    int n;

    cin >> n;
    fill(&left_child[1], &left_child[n+1], 0);
    fill(&right_child[1], &right_child[n+1], 0);

    for (int i = 1; i <= n; i++) {
        cin >> preorder[i];
    }

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        inorder_pos[v] = i;
    }

    return n;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        int size_of_tree = input();
        int root = build_tree(1, 1, size_of_tree);
        postorder(root, '\n');
    }

    return 0;
}