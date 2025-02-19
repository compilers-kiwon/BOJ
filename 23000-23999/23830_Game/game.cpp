#include <iostream>
#include <cstdint>

using namespace std;

#define MAX_SIZE (100000+1)
#define MAX_SCORE (100000)
#define MAX_NUM (UINT64_MAX)

uint64_t N, A[MAX_SIZE], p, q, r, S;

void input(void) {
    cin>>N;

    for (uint64_t i = 1; i <= N; i++) {
        cin>>A[i];
    }

    cin>>p>>q>>r>>S;
}

bool check_score(uint64_t K) {
    uint64_t sum = 0;

    for (uint64_t i = 1; i <= N; i++) {
        if (A[i] > (K + r)) {
            sum += A[i] - p;
        } else if (A[i] < K) {
            sum += A[i] + q;
        } else {
            sum += A[i];
        }
    }

    return (sum >= S);
}

uint64_t simulate(void) {
    uint64_t ret = MAX_NUM;

    uint64_t low = 1;
    uint64_t hi = MAX_SCORE + q + 1;
    uint64_t mid = (low + hi)/2;

    for (; low < hi; mid = (low + hi)/2) {
        if (check_score(mid) == true) {
            ret = min(ret, mid);
            hi = mid;
        } else {
            low = mid + 1;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    uint64_t K;

    input();
    K =simulate();

    if (K == MAX_NUM) {
        cout<<"-1\n";
    } else {
        cout<<K<<'\n';
    }

    return 0;
}