#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)

typedef long long int int64;

enum {
    FEMALE = 0,
    MALE = 1,
    NUM_OF_SEX = 2,
};

int N, M, parent[MAX_SIZE];
int64 cnt[MAX_SIZE][NUM_OF_SEX];

int find_parent(int cur) {
    int& ret = parent[cur];

    if (cur != ret) {
        ret = find_parent(ret);
    }

    return ret;
}

static inline int64 get_num_of_pairs(int p) {
    return (cnt[p][FEMALE] * cnt[p][MALE]);
}

void simulate(void) {
    int64 total_cnt = 0LL;

    for (int i = 1; i <= M; i++) {
        int a, b;
        int a_parent, b_parent;

        cin >> a >> b;
        a_parent = find_parent(a);
        b_parent = find_parent(b);

        if (a_parent != b_parent) {
            int min_p = min(a_parent, b_parent);
            int max_p = max(a_parent, b_parent);

            parent[max_p] = min_p;
            total_cnt -= get_num_of_pairs(min_p) + get_num_of_pairs(max_p);

            cnt[min_p][FEMALE] += cnt[max_p][FEMALE];
            cnt[min_p][MALE] += cnt[max_p][MALE];
            total_cnt += get_num_of_pairs(min_p);
        }

        cout << total_cnt << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;
        parent[i] = i, cnt[i][c%2] = 1LL;
    }

    simulate();

    return 0;
}