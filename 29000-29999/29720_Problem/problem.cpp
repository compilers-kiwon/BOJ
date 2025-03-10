#include <iostream>
#include <vector>

using namespace std;

static inline bool in_range(int min_num, int cur_num, int max_num) {
    return ((min_num <= cur_num) && (cur_num <= max_num));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, K;
    vector<int> solved;

    cin>>N>>M>>K;

    for (int i = 0; i < N + M; i++) {
        int cur = i + (M*K);

        if (in_range(N, cur, N+M-1) == true) {
            solved.push_back(i);
        }
    }

    cout<<solved.front()<<' '<<solved.back()<<'\n';
    return 0;
}