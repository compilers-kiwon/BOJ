#include <iostream>

using namespace std;

#define MAX_SIZE (50000+1)

int N, sum[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int total, max_dist, d;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        cin>>d;
        sum[i] = sum[i-1] + d;
    }

    max_dist = 0, total = sum[N];
    
    for (int from = 1, to = 1;;) {
        int cur_dist, min_dist;

        cur_dist = sum[to] - sum[from-1];
        max_dist = max(max_dist, 
                        min(cur_dist, total - cur_dist));

        if (cur_dist < (total >> 1)) {
            if (to++ == N) {
                break;
            }
        } else {
            if (from < to) {
                from++;
            } else {
                if (to++ == N) {
                    break;
                }
            }
        }
    }

    cout<<max_dist<<'\n';
    return 0;
}