#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)

int postorder[MAX_SIZE];
int inorder_pos[MAX_SIZE];
int left_child[MAX_SIZE], right_child[MAX_SIZE];

int build_tree(int postorder_root, int left, int right) {
    int ret = postorder[postorder_root];
    int mid = inorder_pos[ret];

    int num_of_left = mid - left;
    int num_of_right = right - mid;

    if (num_of_left > 0) {
        left_child[ret] = build_tree(postorder_root - num_of_right -1 , left, mid - 1);
    }

    if (num_of_right > 0) {
        right_child[ret] = build_tree(postorder_root - 1, mid + 1, right);
    }

    return ret;
}

void preorder(int v) {
    cout << v << ' ';

    if (left_child[v] != 0) {
        preorder(left_child[v]);
    }

    if (right_child[v] != 0) {
        preorder(right_child[v]);
    }
}

int input(void) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        inorder_pos[v] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }

    return n;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int size_of_tree = input();
    int root = build_tree(size_of_tree, 1, size_of_tree);
    preorder(root); cout << '\n';

    return 0;
}