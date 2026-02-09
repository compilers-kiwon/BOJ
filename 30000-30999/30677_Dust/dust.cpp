#include <iostream>

using namespace std;

typedef long long int int64;

typedef struct {
    int64 base, s;
    int p;
} Magic;

#define MAX_SIZE (100000+1)
#define MAX_TIRED (100LL)

int N, K, C, R, l[MAX_SIZE];
int64 num_of_used[MAX_SIZE];
Magic m[MAX_SIZE];

int64 get_num_of_dusts(int i, int64 combo) {
    int64 d = m[i].base * (100LL + (combo * (int64)C))
                * (100LL + (num_of_used[i] * m[i].s));
    return (d / 10000LL);
}

int64 simulate(void) {
    int64 ret = 0LL;
    int cur_tired = 0;
    int64 cur_combo = 0LL;
    
    for (int i = 1; i <= N; ++i) {
        if (l[i] == 0) {
            cur_tired = max(0, cur_tired - R);
            cur_combo = 0LL;
            continue;
        }

        ret += get_num_of_dusts(l[i], cur_combo);
        ++cur_combo, ++num_of_used[l[i]], cur_tired += m[l[i]].p;

        if (cur_tired > MAX_TIRED) {
            ret = -1LL;
            break;
        }
    }

    return ret;
}

void input(void) {
    cin >> N >> K >> C >> R;

    for (int i = 1; i <= K; ++i) {
        cin >> m[i].base;
    }

    for (int i = 1; i <= K; ++i) {
        cin >> m[i].s;
    }

    for (int i = 1; i <= K; ++i) {
        cin >> m[i].p;
    }

    for (int i = 1; i <= N; ++i) {
        cin >> l[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}