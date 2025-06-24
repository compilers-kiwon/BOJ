#include <iostream>

#define MAX_SIZE (1000000+1)
#define MOD(n) ((n)%1000000007)

#define LEFT_CHILD(n) (2*(n))
#define RIGHT_CHILD(n) (LEFT_CHILD((n)) + 1)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef long long int int64;

int N, M, K;
int64 num[MAX_SIZE], tree[MAX_SIZE*4];

void input(void) {
    std::cin>>N>>M>>K;

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
        ret = MOD(build_tree(start, mid, LEFT_CHILD(node))
                    * build_tree(mid + 1, end, RIGHT_CHILD(node)));
    }

    return ret;
}

int64 query(int start, int end, int node, int left, int right) {
    if (start > right || end < left) {
        return 1;
    }

    if (start >= left && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return MOD(query(start, mid, LEFT_CHILD(node), left, right)
                *query(mid + 1, end, RIGHT_CHILD(node), left, right));
}

void update(int start, int end, int node, int idx, int64 val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        
        if (idx <= mid) {
            update(start, mid, LEFT_CHILD(node), idx, val);
        } else {
            update(mid + 1, end, RIGHT_CHILD(node), idx, val);
        }

        tree[node] = MOD(tree[LEFT_CHILD(node)] * tree[RIGHT_CHILD(node)]);
    }
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    input();
    build_tree(1, N, 1);

    for (int i = 1; i <= (M + K); i++) {
        int a, b;
        int64 c;

        std::cin>>a>>b>>c;

        if (a == 1) {
            if(IN_RANGE(1, b, N) == true) {
                num[b] = c;
                update(1, N, 1, b, c);
            }
        } else { // a == 2
            std::cout<<query(1, N, 1, b, (int)c)<<'\n';
        }
    }

    return 0;
}